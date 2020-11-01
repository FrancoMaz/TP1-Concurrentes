//
// Created by francomazzoni on 26/10/20.
//

#include "Ajustador.h"
#include "Imagen.h"

Ajustador::Ajustador(int parametroDeAjuste) {
    this->parametroDeAjuste = parametroDeAjuste;
}

void Ajustador::ajustarImagen(Imagen *imagen) const {
    imagen->ajustar(this->parametroDeAjuste);
}

void Ajustador::ajustarImagen(Imagen imagen) const {
    imagen.ajustar(this->parametroDeAjuste);
}