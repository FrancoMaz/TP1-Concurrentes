#include <iostream>
#include "../Camara.h"
#include "../Imagen.h"
#include "../Aplanador.h"
#include "../Ajustador.h"
#include "../senial/SIGINT_handler.h"
#include "../senial/SignalHandler.h"
#include "MemoriaCompartida.h"
#include <unistd.h>
#include <wait.h>

using namespace std;

vector<Imagen> generarImagenes(int cantidadCamaras, int pixelesPorFila) {

    auto camara = Camara(Imagen(0));

    vector<Imagen> imagenes;
    imagenes.reserve(cantidadCamaras);

    for (int i = 0; i < cantidadCamaras; i++) {
        imagenes.push_back(camara.generarImagen(pixelesPorFila));
    }

    return imagenes;
};

int* serializarImagenes(vector<Imagen> imagenes, int pixelesPorFila, int arraySize) {
    int* imagenesSerializadas = new int[arraySize];

    int position = 0;
    while (position < arraySize) {
        for (auto & imagen : imagenes) {
            cout << "Imagen normal: " << imagen.mostrar() << endl;
            for (int j = 0; j < pixelesPorFila * pixelesPorFila; j++) {
                imagenesSerializadas[position] = imagen.getPixel(j);
                position++;
            }
        }
    }

    return imagenesSerializadas;

}

vector<Imagen> deserializarImagenes(int* imagenes, int pixelesPorFila, int arraySize) {
    vector<Imagen> imagenesDeserializadas;

    for (int i = 0; i < arraySize; i += (pixelesPorFila * pixelesPorFila)) {
        Imagen imagen = Imagen(pixelesPorFila);
        for (int j = i; j < i + (pixelesPorFila * pixelesPorFila); j++) {
            imagen.agregarPixel(imagenes[j]);
        }
        cout << "Imagen ajustada: " << imagen.mostrar() << endl;
        imagenesDeserializadas.push_back(imagen);
    }

    return imagenesDeserializadas;

}

Imagen deserializarImagen(int* imagenesASerializar, int pixelesPorFila) {
    auto imagen = Imagen(pixelesPorFila);

    for (int i = 0; i < pixelesPorFila * pixelesPorFila; i++) {
        imagen.agregarPixel(imagenesASerializar[i]);

    }
    return imagen;
}

int* serializarImagen(Imagen imagen, int pixelesPorFila) {
    int* imagenADevolver = new int[pixelesPorFila];

    for (int i = 0; i < pixelesPorFila * pixelesPorFila; i++) {
        imagenADevolver[i] = imagen.getPixel(i);
    }
    return imagenADevolver;
}

vector<Imagen> ajustarImagenes(const vector<Imagen> imagenes, int pixelesPorFila) {

    string archivo = "/bin/ls";

    int arraySize = pixelesPorFila * pixelesPorFila * imagenes.size();

    auto *ajustador = new Ajustador(10);

    MemoriaCompartida buffer(archivo,'A', arraySize);
    buffer.escribir(serializarImagenes(imagenes, pixelesPorFila, arraySize), 0, arraySize);

    pid_t ids[imagenes.size()];

    for (int i = 0; i < imagenes.size(); i++) {
        ids[i] = fork();
        if (ids[i] == 0) {
            try {
                int offset = i * pixelesPorFila * pixelesPorFila;
                MemoriaCompartida bufferHijo(archivo, 'A', arraySize);
                int *resultado = bufferHijo.leer(offset, pixelesPorFila * pixelesPorFila);
                Imagen imagenDeserializada = deserializarImagen(resultado, pixelesPorFila);
                ajustador->ajustarImagen(&imagenDeserializada);
                bufferHijo.escribir(serializarImagen(imagenDeserializada, pixelesPorFila), offset, pixelesPorFila * pixelesPorFila);

            } catch(string& message) {
                cerr << message << endl;
            }
            exit(0);
        }
    }

    for (int i = 0; i < imagenes.size(); i++) {
        waitpid(ids[i], nullptr, 0);
    }

    int *resultado = buffer.leer(0, arraySize);
    return deserializarImagenes(resultado, pixelesPorFila, arraySize);

}

int main() {

    int cantidadCamaras;
    int pixelesPorFila;

    cout << "Ingresar cantidad de cámaras: " << endl;
    cin >> cantidadCamaras;
    cout << "Ingresar el número de píxeles por fila (las imágenes son NxN): " << endl;
    cin >> pixelesPorFila;

    vector<Imagen> imagenes = generarImagenes(cantidadCamaras, pixelesPorFila);

    /*SIGINT_Handler sigchld_handler;
    SignalHandler::getInstance()->registrarHandler(SIGCHLD, &sigchld_handler);*/

    vector<Imagen> imagenesAjustadas = ajustarImagenes(imagenes, pixelesPorFila);

    //SignalHandler::destruir();

    Aplanador::aplanarImagenes(imagenesAjustadas, pixelesPorFila);

    return 0;
}
