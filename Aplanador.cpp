//
// Created by francomazzoni on 24/10/20.
//

#include "Aplanador.h"
#include <iostream>
#include <vector>
using namespace std;

Imagen* Aplanador::aplanarImagenes(vector<Imagen*> imagenes, int pixelesPorFila) {
    auto *imagenResultante = new Imagen(pixelesPorFila);
    int pixelesImagenes = pixelesPorFila * pixelesPorFila;

    for (int i = 0; i < pixelesImagenes; i++) {
        int pixelResultante = 0;
        for (auto & imagen : imagenes) {
            pixelResultante += imagen->getPixel(i);
        }
        imagenResultante->agregarPixel(pixelResultante);
    }

    cout << "Imagen aplanada: " << imagenResultante->mostrar() << endl;
    return imagenResultante;
}