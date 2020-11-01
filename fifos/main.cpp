#include <iostream>
#include "../Camara.h"
#include "../Imagen.h"
#include "../Aplanador.h"
#include "../Ajustador.h"
#include "../senial/SIGINT_handler.h"
#include "../senial/SignalHandler.h"
#include "FifoEscritura.h"
#include "FifoLectura.h"
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

int* serializarImagenes(vector<Imagen*> imagenes, int pixelesPorFila, int arraySize) {
    int* imagenesSerializadas = new int[arraySize];

    int position = 0;
    while (position < arraySize) {
        for (auto & imagen : imagenes) {
            for (int j = 0; j < pixelesPorFila * pixelesPorFila; j++) {
                imagenesSerializadas[position] = imagen->getPixel(j);
                position++;
            }
        }
    }

    return imagenesSerializadas;

}

vector<Imagen*> deserializarImagenes(int* imagenes, int pixelesPorFila, int arraySize) {
    vector<Imagen*> imagenesDeserializadas;

    for (int i = 0; i < arraySize; i += (pixelesPorFila * pixelesPorFila)) {
        Imagen *imagen = new Imagen(pixelesPorFila);
        for (int j = i; j < i + (pixelesPorFila * pixelesPorFila); j++) {
            imagen->agregarPixel(imagenes[j]);
        }
        imagenesDeserializadas.push_back(imagen);
    }

    return imagenesDeserializadas;

}

Imagen* deserializarImagen(int* imagenesASerializar, int pixelesPorFila) {
    auto* imagen = new Imagen(pixelesPorFila);

    for (int i = 0; i < pixelesPorFila * pixelesPorFila; i++) {
        imagen->agregarPixel(imagenesASerializar[i]);

    }
    return imagen;
}

int* serializarImagen(Imagen* imagen, int pixelesPorFila) {
    int* imagenADevolver = new int[pixelesPorFila];

    for (int i = 0; i < pixelesPorFila * pixelesPorFila; i++) {
        imagenADevolver[i] = imagen->getPixel(i);
    }
    return imagenADevolver;
}


vector<Imagen*> ajustarImagenes(const vector<Imagen*> imagenes, int pixelesPorFila) {

    int arraySize = pixelesPorFila * pixelesPorFila * imagenes.size();
    int bufferSize = arraySize*sizeof(int);
    string archivo = "/tmp/archivo_fifo";

    cout << "Imagenes normales" << endl;
    for (int i = 0; i < imagenes.size(); i++) {
        cout << "Imagen " << i+1 << ": " << imagenes[i]->mostrar() << endl;
    }

    auto *ajustador = new Ajustador(10);

    pid_t ids[imagenes.size()];
    vector<Imagen*> imagenesAjustadas;

    for (int i = 0; i < imagenes.size(); i++) {
        ids[i] = fork();
        if (ids[i] == 0) {
            FifoLectura canalLectura(archivo);
            int buffer[pixelesPorFila*pixelesPorFila*sizeof(int)];
            canalLectura.abrir();
            canalLectura.leer(static_cast<void*>(buffer), pixelesPorFila*pixelesPorFila*sizeof(int));
            Imagen* imagen = deserializarImagen(buffer, pixelesPorFila);
            ajustador->ajustarImagen(imagen);
            cout << "Proceso " << i << " ajusta a imagen: " << imagen->mostrar() << endl;
            imagenesAjustadas.push_back(imagen);
            canalLectura.cerrar();
            exit(0);
        } else {
            cout << "Padre " << i << endl;
            FifoEscritura canalEscritura(archivo);
            canalEscritura.abrir();
            //int* imagenesSerializadas = serializarImagenes(imagenes, pixelesPorFila, arraySize);
            int* imagenSerializada = serializarImagen(imagenes[i], pixelesPorFila);
            canalEscritura.escribir(static_cast<void*>(imagenSerializada), bufferSize);
            waitpid(ids[i], nullptr, 0);
            canalEscritura.cerrar();
            canalEscritura.eliminar();
        }
    }

    /*for (int i = 0; i < imagenes.size(); i++) {
        waitpid(ids[i], nullptr, 0);
    }*/

    cout << endl;
    cout << imagenesAjustadas.size() << endl;
    cout << "Imagenes ajustadas" << endl;
    for (int i = 0; i < imagenesAjustadas.size(); i++) {
        cout << "Imagen " << i+1 << ": " << imagenesAjustadas[i]->mostrar() << endl;
    }

    return imagenesAjustadas;

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

    vector<Imagen*> imagenesAjustadas = ajustarImagenes(imagenes, pixelesPorFila);

    //SignalHandler::destruir();

    //Aplanador::aplanarImagenes(imagenesAjustadas, pixelesPorFila);

    return 0;
}
