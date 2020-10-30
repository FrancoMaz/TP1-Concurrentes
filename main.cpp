#include <iostream>
#include "Camara.h"
#include "Imagen.h"
#include "Aplanador.h"
#include "Ajustador.h"
#include "senial/SIGINT_handler.h"
#include "senial/SignalHandler.h"
#include <unistd.h>

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

void ajustarImagenes(vector<Imagen*> imagenes) {

    pid_t ids[imagenes.size()];
    auto *ajustador = new Ajustador(10);

    for (int i = 0; i < imagenes.size(); i++) {
        ids[i] = fork();
        if (ids[i] == 0) {
            cout << "Proceso hijo " << i << endl;
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

    SIGINT_Handler sigchld_handler;
    SignalHandler::getInstance()->registrarHandler(SIGCHLD, &sigchld_handler);

    ajustarImagenes(imagenes);

    int contador = 1;

    while (sigchld_handler.getGracefulQuit() == 0 && contador < imagenes.size()) {
        if (sigchld_handler.getGracefulQuit() == 0) {
            contador++;
            cout << contador << endl;
        }
    }

    SignalHandler::destruir();

    Aplanador::aplanarImagenes(imagenes, pixelesPorFila);

    return 0;
}
