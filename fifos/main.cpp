#include <iostream>
#include "../Camara.h"
#include "../Aplanador.h"
#include "../Ajustador.h"
#include "../senial/SIGINT_handler.h"
#include "../senial/SignalHandler.h"
#include "FifoEscritura.h"
#include "FifoLectura.h"
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

Imagen deserializarImagen(int* imagenesASerializar, int pixelesPorFila) {
    auto imagen = Imagen(pixelesPorFila*pixelesPorFila);

    for (int i = 0; i < pixelesPorFila * pixelesPorFila; i++) {
        imagen.agregarPixel(imagenesASerializar[i]);
    }

    return imagen;
}

int* serializarImagen(Imagen imagen, int pixelesPorFila) {
    int* imagenADevolver = new int[pixelesPorFila*pixelesPorFila];

    for (int i = 0; i < pixelesPorFila * pixelesPorFila; i++) {
        imagenADevolver[i] = imagen.getPixel(i);
    }
    return imagenADevolver;
}

void mostrarImagenes(vector<Imagen*> imagenes) {

    for (int i = 0; i < imagenes.size(); i++) {

    }
}


vector<Imagen> ajustarImagenes(const vector<Imagen> imagenes, int pixelesPorFila) {

    int arraySize = pixelesPorFila * pixelesPorFila * imagenes.size();
    int bufferSize = arraySize*sizeof(int);
    string archivo = "/tmp/archivo_fifo";
    string archivo1 = "/tmp/archivo_fifo_2";

    cout << "Imagenes normales" << endl;
    for (int i = 0; i < imagenes.size(); i++) {
        cout << "Imagen " << i+1 << ": " << imagenes[i].mostrar() << endl;
    }

    auto *ajustador = new Ajustador(10);
    vector<Imagen> imagenesAjustadas;

    pid_t ids[imagenes.size()];

    for (int i = 0; i < imagenes.size(); i++) {
        ids[i] = fork();
        if (ids[i] == 0) {
            //Lectura
            FifoLectura canalLectura(archivo);
            int buffer[pixelesPorFila*pixelesPorFila*sizeof(int)];
            canalLectura.abrir();
            canalLectura.leer(buffer, pixelesPorFila*pixelesPorFila*sizeof(int));
            //Deserialización
            Imagen imagen = deserializarImagen(buffer, pixelesPorFila);
            ajustador->ajustarImagen(&imagen);
            //Serialización
            int* imagenAjustada = serializarImagen(imagen, pixelesPorFila);
            canalLectura.cerrar();
            //Escritura
            FifoEscritura canalEscritura(archivo1);
            canalEscritura.abrir();
            canalEscritura.escribir(imagenAjustada, bufferSize);
            canalEscritura.cerrar();
            exit(0);
        } else {
            //Escritura
            FifoEscritura canalEscritura(archivo);
            canalEscritura.abrir();
            int* imagenSerializada = serializarImagen(imagenes[i], pixelesPorFila);
            canalEscritura.escribir(imagenSerializada, bufferSize);
            canalEscritura.cerrar();
            canalEscritura.eliminar();
            //Lectura
            FifoLectura canalLectura(archivo1);
            int buffer[pixelesPorFila*pixelesPorFila*sizeof(int)];
            canalLectura.abrir();
            canalLectura.leer(buffer, pixelesPorFila*pixelesPorFila*sizeof(int));
            //Deserialización
            Imagen imagen = deserializarImagen(buffer, pixelesPorFila);
            imagenesAjustadas.push_back(imagen);
            waitpid(ids[i], nullptr, 0);
            canalLectura.cerrar();
            canalLectura.eliminar();
        }
    }

    cout << endl;
    cout << "Imagenes ajustadas" << endl;
    for (int i = 0; i < imagenesAjustadas.size(); i++) {
        cout << "Imagen " << i+1 << ": " << imagenesAjustadas[i].mostrar() << endl;
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

    SIGINT_Handler sigint_handler;
    SignalHandler::getInstance()->registrarHandler(SIGINT, &sigint_handler);

    while (sigint_handler.getGracefulQuit() == 0) {

        vector<Imagen> imagenes = generarImagenes(cantidadCamaras, pixelesPorFila);
        vector<Imagen> imagenesAjustadas = ajustarImagenes(imagenes, pixelesPorFila);

        Aplanador::aplanarImagenes(imagenesAjustadas, pixelesPorFila);
    }

    SignalHandler::destruir();
    cout << "Fin del proceso" << endl;

    return 0;
}
