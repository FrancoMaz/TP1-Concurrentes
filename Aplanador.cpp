//
// Created by francomazzoni on 24/10/20.
//

#include "Aplanador.h"
#include <iostream>
#include <vector>
using namespace std;

//El algoritmo de aplanado suma píxel con píxel de todas las imagenes capturadas
Imagen Aplanador::aplanarImagenes(vector<Imagen> imagenes, int pixelesPorFila) {
    auto imagenResultante = Imagen(pixelesPorFila);
    int pixelesImagenes = pixelesPorFila * pixelesPorFila;

    for (int i = 0; i < pixelesImagenes; i++) {
        int pixelResultante = 0;
        for (auto & imagen : imagenes) {
            pixelResultante += imagen.getPixel(i);
        }
        imagenResultante.agregarPixel(pixelResultante);
    }

    return imagenResultante;
}