//
// Created by francomazzoni on 26/10/20.
//

#ifndef CONCURRENTES_AJUSTADOR_H
#define CONCURRENTES_AJUSTADOR_H


#include "Imagen.h"

class Ajustador {
private:
    int parametroDeAjuste;
public:
    explicit Ajustador(int parametroDeAjuste);
    void ajustarImagen(Imagen *imagen) const;

    void ajustarImagen(Imagen imagen) const;
};


#endif //CONCURRENTES_AJUSTADOR_H
