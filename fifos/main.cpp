#include <iostream>
#include "../Camara.h"
#include "../Aplanador.h"
#include "../Ajustador.h"
#include "../senial/SIGINT_handler.h"
#include "../senial/SignalHandler.h"
#include "FifoEscritura.h"
#include "FifoLectura.h"
#include "../Log.h"
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

void mostrarImagenes(vector<Imagen> imagenes, Log log) {

    for (int i = 0; i < imagenes.size(); i++) {
        log.escribirAArchivo("Imagen " + to_string(i+1) + ": " + imagenes[i].mostrar(), "DEBUG");
    }
}

vector<Imagen> ajustarImagenes(const vector<Imagen> imagenes, int pixelesPorFila) {

    int arraySize = pixelesPorFila * pixelesPorFila * imagenes.size();
    int bufferSize = arraySize*sizeof(int);
    string archivo1 = "/tmp/archivo_fifo";
    string archivo2 = "/tmp/archivo_fifo_2";

    auto *ajustador = new Ajustador(10);
    vector<Imagen> imagenesAjustadas;

    pid_t ids[imagenes.size()];

    for (int i = 0; i < imagenes.size(); i++) {
        ids[i] = fork();
        if (ids[i] == 0) {
            //Lectura
            FifoLectura canalLectura(archivo1 + "_" + to_string(i));
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
            FifoEscritura canalEscritura(archivo2 + "_" + to_string(i));
            canalEscritura.abrir();
            canalEscritura.escribir(imagenAjustada, bufferSize);
            canalEscritura.cerrar();
            exit(0);
        } else {
            //Escritura
            FifoEscritura canalEscritura(archivo1 + "_" + to_string(i));
            canalEscritura.abrir();
            int* imagenSerializada = serializarImagen(imagenes[i], pixelesPorFila);
            canalEscritura.escribir(imagenSerializada, bufferSize);
            canalEscritura.cerrar();
            canalEscritura.eliminar();
        }
    }

    for (int i = 0; i < imagenes.size(); i++) {
        //Lectura
        FifoLectura canalLectura(archivo2 + "_" + to_string(i));
        int buffer[pixelesPorFila*pixelesPorFila*sizeof(int)];
        canalLectura.abrir();
        canalLectura.leer(buffer, pixelesPorFila*pixelesPorFila*sizeof(int));
        //Deserialización
        Imagen imagen = deserializarImagen(buffer, pixelesPorFila);
        imagenesAjustadas.push_back(imagen);
        canalLectura.cerrar();
        canalLectura.eliminar();
    }

    return imagenesAjustadas;

}

int main() {

    int cantidadCamaras;
    int pixelesPorFila;
    string modoDebug;
    int maxCantidadCiclos;
    bool modoDebugActivado = false;

    cout << "Ingresar cantidad de cámaras: " << endl;
    cin >> cantidadCamaras;
    cout << "Ingresar el número de píxeles por fila (las imágenes son NxN): " << endl;
    cin >> pixelesPorFila;
    cout << "Ingresar la cantidad de veces que se ejecutará la generación de imagenes: " << endl;
    cin >> maxCantidadCiclos;
    while (modoDebug != "Y" && modoDebug != "N" && modoDebug != "y" && modoDebug != "n") {
        cout << "Desea ejecutar en modo debug? (Y/N) " << endl;
        cin >> modoDebug;
    }

    if (modoDebug == "Y" || modoDebug == "y") {
        modoDebugActivado = true;
    }

    Log log = Log("output_ej2.txt", modoDebugActivado);

    cout << "Loggeando en el archivo output_ej2.txt. Presiona CTRL + C para finalizar" << endl;

    log.escribirAArchivo("Comenzando el proceso con " + to_string(cantidadCamaras) + " imagenes de " + to_string(pixelesPorFila) +
                         "X" + to_string(pixelesPorFila), "INFO", true);

    SIGINT_Handler sigint_handler;
    SignalHandler::getInstance()->registrarHandler(SIGINT, &sigint_handler);

    int cantidadCiclos = 0;

    while (sigint_handler.getGracefulQuit() == 0 && cantidadCiclos < maxCantidadCiclos) {
        cantidadCiclos++;

        log.escribirAArchivo("Comienza el ciclo " + to_string(cantidadCiclos), "INFO");

        log.escribirAArchivo("Generando imagenes...", "INFO");
        vector<Imagen> imagenes = generarImagenes(cantidadCamaras, pixelesPorFila);
        mostrarImagenes(imagenes, log);

        log.escribirAArchivo("Ajustando imagenes...", "INFO");
        vector<Imagen> imagenesAjustadas = ajustarImagenes(imagenes, pixelesPorFila);
        mostrarImagenes(imagenesAjustadas, log);

        log.escribirAArchivo("Aplanando imagenes...", "INFO");
        Imagen imagenAplanada = Aplanador::aplanarImagenes(imagenesAjustadas, pixelesPorFila);
        log.escribirAArchivo("Imagen aplanada: " + imagenAplanada.mostrar(), "DEBUG");
    }

    SignalHandler::destruir();
    cout << "Fin del proceso" << endl;

    return 0;
}
