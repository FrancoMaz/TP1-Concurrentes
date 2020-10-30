//
// Created by francomazzoni on 24/10/20.
//

#ifndef CONCURRENTES_APLANADOR_H
#define CONCURRENTES_APLANADOR_H


#include "Imagen.h"
#include <vector>

using namespace std;

class Aplanador {

public:
    static Imagen aplanarImagenes(vector<Imagen*> imagenes, int pixelesPorFila);
};


#endif //CONCURRENTES_APLANADOR_H
