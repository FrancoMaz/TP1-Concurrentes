#include <iostream>
#include "../Camara.h"
#include "../Aplanador.h"
#include "../Ajustador.h"
#include "../senial/SIGINT_handler.h"
#include "../senial/SignalHandler.h"
#include "../Log.h"
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

void mostrarImagenes(vector<Imagen> imagenes, Log log) {

    for (int i = 0; i < imagenes.size(); i++) {
        log.escribirAArchivo("Imagen " + to_string(i+1) + ": " + imagenes[i].mostrar(), "DEBUG");
    }
}

int* serializarImagenes(vector<Imagen> imagenes, int pixelesPorFila, size_t arraySize) {
    int* imagenesSerializadas = new int[arraySize];

    int position = 0;
    while (position < arraySize) {
        for (auto &imagen : imagenes) {
            for (int j = 0; j < pixelesPorFila * pixelesPorFila; j++) {
                imagenesSerializadas[position] = imagen.getPixel(j);
                position++;
            }
        }
    }

    return imagenesSerializadas;

}

vector<Imagen> deserializarImagenes(int* imagenes, int pixelesPorFila, size_t arraySize) {
    vector<Imagen> imagenesDeserializadas;

    for (size_t i = 0; i < arraySize; i += (pixelesPorFila * pixelesPorFila)) {
        Imagen imagen = Imagen(pixelesPorFila);
        for (int j = i; j < i + (pixelesPorFila * pixelesPorFila); j++) {
            imagen.agregarPixel(imagenes[j]);
        }
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
    int* imagenADevolver = new int[pixelesPorFila * pixelesPorFila];

    for (int i = 0; i < pixelesPorFila * pixelesPorFila; i++) {
        imagenADevolver[i] = imagen.getPixel(i);
    }
    return imagenADevolver;
}

vector<Imagen> ajustarImagenes(const vector<Imagen>& imagenes, int pixelesPorFila) {

    string archivo = "/bin/ls";

    size_t arraySize = pixelesPorFila * pixelesPorFila * imagenes.size();

    Ajustador ajustador = Ajustador(10);

    MemoriaCompartida buffer(archivo,'A', arraySize);
    int* imagenesAEscribir = serializarImagenes(imagenes, pixelesPorFila, arraySize);
    buffer.escribir(imagenesAEscribir, 0, arraySize);
    delete[] imagenesAEscribir;
    pid_t ids[imagenes.size()];

    for (int i = 0; i < imagenes.size(); i++) {
        ids[i] = fork();
        if (ids[i] == 0) {
            try {
                int offset = i * pixelesPorFila * pixelesPorFila;
                MemoriaCompartida bufferHijo(archivo, 'A', arraySize);
                int *resultado = bufferHijo.leer(offset, pixelesPorFila * pixelesPorFila);
                Imagen imagenDeserializada = deserializarImagen(resultado, pixelesPorFila);
                ajustador.ajustarImagen(&imagenDeserializada);
                int* imagenSerializada = serializarImagen(imagenDeserializada, pixelesPorFila);
                bufferHijo.escribir(imagenSerializada, offset, pixelesPorFila * pixelesPorFila);
                delete[] imagenSerializada;
                delete[] resultado;

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
    vector<Imagen> imagenesDeserializadas = deserializarImagenes(resultado, pixelesPorFila, arraySize);
    delete[] resultado;

    return imagenesDeserializadas;

}

int main() {

    int cantidadCamaras;
    int pixelesPorFila;
    string modoDebug;
    int maxCantidadCiclos;
    bool modoDebugActivado = false;

    //Se piden los datos al usuario
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

    //Activar modo debug
    if (modoDebug == "Y" || modoDebug == "y") {
        modoDebugActivado = true;
    }

    //Se loguea en el archivo output_ej1.txt
    Log log = Log("output_ej1.txt", modoDebugActivado);

    cout << "Loggeando en el archivo output_ej1.txt. Presiona CTRL + C para finalizar" << endl;

    log.escribirAArchivo("Comenzando el proceso con " + to_string(cantidadCamaras) + " imagenes de " + to_string(pixelesPorFila) +
    "X" + to_string(pixelesPorFila), "INFO", true);

    //Se registra el handler para la señal SIGINT
    SIGINT_Handler sigint_handler;
    SignalHandler::getInstance()->registrarHandler(SIGINT, &sigint_handler);

    int cantidadCiclos = 0;

    //Si se detecta la señal SIGINT (el usuario ingresa CTRL + C) o se llega a la máxima cantidad de ciclos, entonces el proceso termina
    while (sigint_handler.getGracefulQuit() == 0 && cantidadCiclos < maxCantidadCiclos) {
        cantidadCiclos++;

        log.escribirAArchivo("Comienza el ciclo " + to_string(cantidadCiclos), "INFO");

        //Generación de imagenes
        log.escribirAArchivo("Generando imagenes...", "INFO");
        vector<Imagen> imagenes = generarImagenes(cantidadCamaras, pixelesPorFila);
        mostrarImagenes(imagenes, log);

        //Ajuste de imagenes
        log.escribirAArchivo("Ajustando imagenes...", "INFO");
        vector<Imagen> imagenesAjustadas = ajustarImagenes(imagenes, pixelesPorFila);
        mostrarImagenes(imagenesAjustadas, log);

        //Aplanado de imagenes
        log.escribirAArchivo("Aplanando imagenes...", "INFO");
        Imagen imagenAplanada = Aplanador::aplanarImagenes(imagenesAjustadas, pixelesPorFila);
        log.escribirAArchivo("Imagen aplanada: " + imagenAplanada.mostrar(), "DEBUG");

        imagenes.clear();
        imagenesAjustadas.clear();

    }

    SignalHandler::destruir();
    cout << "Fin del proceso" << endl;

    return 0;
}
