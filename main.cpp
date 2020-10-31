#include <iostream>
#include "Camara.h"
#include "Imagen.h"
#include "Aplanador.h"
#include "Ajustador.h"
#include "senial/SIGINT_handler.h"
#include "senial/SignalHandler.h"
#include "MemoriaCompartida.h"
#include <unistd.h>
#include <wait.h>

using namespace std;

vector<Imagen*> generarImagenes(int cantidadCamaras, int pixelesPorFila) {

    auto *camara = new Camara();

    vector<Imagen*> imagenes;
    imagenes.reserve(cantidadCamaras);

    for (int i = 0; i < cantidadCamaras; i++) {
        imagenes.push_back(camara->generarImagen(pixelesPorFila));
    }

    return imagenes;
};

int* serializarImagenes(vector<Imagen*> imagenes, int pixelesPorFila, int arraySize, int proceso) {
    int* imagenesSerializadas = new int[arraySize];

    int position = 0;
    while (position < arraySize) {
        for (auto & imagen : imagenes) {
            cout << "Proceso " << proceso << " serializa imagen " << imagen->mostrar() << endl;
            for (int j = 0; j < pixelesPorFila * pixelesPorFila; j++) {
                imagenesSerializadas[position] = imagen->getPixel(j);
                position++;
            }
        }
    }

    return imagenesSerializadas;

}

vector<Imagen*> deserializarImagenes(int* imagenesASerializar, int pixelesPorFila, int cantidadImagenes, int arraySize, int proceso) {
    vector<Imagen*> imagenesDeserializadas;

    int position = 0;
    while (position < arraySize) {
        for (int i = 0; i < cantidadImagenes; i++) {
            auto *imagen = new Imagen(pixelesPorFila);
            for (int j = 0; j < pixelesPorFila * pixelesPorFila; j++) {
                imagen->agregarPixel(imagenesASerializar[position]);
                position++;
            }
            cout << "Proceso " << proceso << " deserializa imagen " << imagen->mostrar() << endl;
            imagenesDeserializadas.push_back(imagen);
        }
    }

    return imagenesDeserializadas;
}

void ajustarImagenes(const vector<Imagen*>& imagenes, int pixelesPorFila) {

    string archivo = "/bin/ls";

    int arraySize = pixelesPorFila * pixelesPorFila * imagenes.size();

    auto *ajustador = new Ajustador(10);

    MemoriaCompartida<int*> buffer(archivo,'A', arraySize);
    buffer.escribir(serializarImagenes(imagenes, pixelesPorFila, arraySize, 0));

    pid_t ids[imagenes.size()];

    for (int i = 0; i < imagenes.size(); i++) {
        ids[i] = fork();
        if (ids[i] == 0) {
            try {
                MemoriaCompartida<int *> bufferHijo(archivo, 'A', arraySize);
                int *resultado = bufferHijo.leer();
                vector<Imagen *> imagenesDeserializadas = deserializarImagenes(resultado, pixelesPorFila, imagenes.size(), arraySize, i + 1);
                ajustador->ajustarImagen(imagenesDeserializadas[i]);
                bufferHijo.escribir(serializarImagenes(imagenesDeserializadas, pixelesPorFila, arraySize, i + 1));

            } catch(string& message) {
                cerr << message << endl;
            }
            exit(0);
        }
    }

    for(int i = 0; i < imagenes.size(); i++) {
        waitpid(ids[i], nullptr, 0);
    }

    int* resultado = buffer.leer();
    vector<Imagen*> imagenesDeserializadas = deserializarImagenes(resultado, pixelesPorFila, imagenes.size(), arraySize, 1000);

}

int main() {

    int cantidadCamaras;
    int pixelesPorFila;

    cout << "Ingresar cantidad de cámaras: " << endl;
    cin >> cantidadCamaras;
    cout << "Ingresar el número de píxeles por fila (las imágenes son NxN): " << endl;
    cin >> pixelesPorFila;

    vector<Imagen*> imagenes = generarImagenes(cantidadCamaras, pixelesPorFila);

    /*SIGINT_Handler sigchld_handler;
    SignalHandler::getInstance()->registrarHandler(SIGCHLD, &sigchld_handler);*/

    ajustarImagenes(imagenes, pixelesPorFila);

    //SignalHandler::destruir();

    Aplanador::aplanarImagenes(imagenes, pixelesPorFila);

    return 0;
}
