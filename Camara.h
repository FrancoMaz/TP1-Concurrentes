//
// Created by francomazzoni on 24/10/20.
//

#ifndef CONCURRENTES_CAMARA_H
#define CONCURRENTES_CAMARA_H

#include "Imagen.h"

class Camara {

private:
    Imagen imagen;

public:

    explicit Camara(const Imagen& imagen);

    Imagen generarImagen(int pixelesPorFila);

};

#endif //CONCURRENTES_CAMARA_H
