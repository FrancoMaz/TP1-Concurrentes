//
// Created by francomazzoni on 24/10/20.
//

#ifndef CONCURRENTES_CAMARA_H
#define CONCURRENTES_CAMARA_H

#include "Imagen.h"

class Camara {

public:
    explicit Camara(int pixeles);

    static void generarImagen();

    static void ajustarImagen();

    static void mostrarImagen();

    static Imagen getImagen();
};


#endif //CONCURRENTES_CAMARA_H
