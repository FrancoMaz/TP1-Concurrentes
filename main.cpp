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

void ajustarImagenes(vector<Imagen*> imagenes, int pixelesPorFila, pid_t ids[]) {

    string archivo = "/bin/ls";

    auto *ajustador = new Ajustador(10);

    int arraySize = pixelesPorFila * pixelesPorFila * imagenes.size() + 1;

    int* imagenesSerializadas = new int[arraySize];
    imagenesSerializadas[0] = arraySize;

    int position = 1;
    while (position < arraySize) {
        for (auto & imagen : imagenes) {
            for (int j = 0; j < pixelesPorFila * pixelesPorFila; j++) {
                imagenesSerializadas[position] = imagen->getPixel(j);
                position++;
            }
        }
    }

    MemoriaCompartida<int*> buffer(archivo,'A');
    buffer.escribir(imagenesSerializadas);

    for (int i = 0; i < imagenes.size(); i++) {
        ids[i] = fork();
        if (ids[i] == 0) {
            cout << "Proceso hijo " << i+1 << endl;
            ajustador->ajustarImagen(imagenes[i]);
            exit(0);
        }
    }
}

int main() {

    int cantidadCamaras;
    int pixelesPorFila;

    cout << "Ingresar cantidad de cámaras: " << endl;
    cin >> cantidadCamaras;
    cout << "Ingresar el número de píxeles por fila (las imágenes son NxN): " << endl;
    cin >> pixelesPorFila;

    vector<Imagen*> imagenes = generarImagenes(cantidadCamaras, pixelesPorFila);
    pid_t ids[imagenes.size()];

    SIGINT_Handler sigchld_handler;
    SignalHandler::getInstance()->registrarHandler(SIGCHLD, &sigchld_handler);

    ajustarImagenes(imagenes, pixelesPorFila, ids);

    for(int i = 0; i < imagenes.size(); i++) {
        waitpid(ids[i], nullptr, 0);
    }

    SignalHandler::destruir();

    Aplanador::aplanarImagenes(imagenes, pixelesPorFila);

    return 0;
}
