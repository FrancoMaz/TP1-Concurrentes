#include <iostream>
#include "Camara.h"
#include "Imagen.h"
#include "Aplanador.h"
#include <list>

using namespace std;

int main() {

    int cantidadCamaras;
    int pixelesPorFila;

    cout << "Ingresar cantidad de cámaras: " << endl;
    cin >> cantidadCamaras;
    cout << "Ingresar el número de píxeles por fila (las imágenes son NxN): " << endl;
    cin >> pixelesPorFila;
    vector<Imagen> imagenes;

    for (int k = 0; k < cantidadCamaras; k++) {
        cout << "Imagen " << k+1 << endl;
        cout << endl;

        auto *camara = new Camara(pixelesPorFila);

        Camara::generarImagen();
        cout << "Imagen original" << endl;
        Camara::mostrarImagen();

        Camara::ajustarImagen();
        cout << "Imagen ajustada" << endl;
        Camara::mostrarImagen();

        imagenes.push_back(Camara::getImagen());

    }

    Aplanador::aplanarImagenes(imagenes, pixelesPorFila);

    return 0;
}
