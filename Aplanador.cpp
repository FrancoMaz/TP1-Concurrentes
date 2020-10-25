//
// Created by francomazzoni on 24/10/20.
//

#include "Aplanador.h"
#include <iostream>
#include <vector>
using namespace std;

Imagen Aplanador::aplanarImagenes(vector<Imagen> imagenes, int pixelesPorFila) {
    auto *imagen = new Imagen(pixelesPorFila);

    for (int i = 0; i < (pixelesPorFila * pixelesPorFila); i++) {
        int pixelResultante = 0;
        for (int j = 0; j < imagenes.size(); j++) {
            pixelResultante += imagenes[j].getPixel(i);
        }
        imagen->agregarPixel(pixelResultante);
    }

    cout << "Imagen aplanada" << endl;
    imagen->mostrar();
    return *imagen;
}