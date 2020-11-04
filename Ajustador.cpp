//
// Created by francomazzoni on 26/10/20.
//

#include "Ajustador.h"
#include "Imagen.h"

Ajustador::Ajustador(int parametroDeAjuste) {
    this->parametroDeAjuste = parametroDeAjuste;
}

//El parámetro de ajuste indica el máximo número que pueden sumar los pixeles de una imagen para ajustarse
void Ajustador::ajustarImagen(Imagen *imagen) const {
    imagen->ajustar(this->parametroDeAjuste);
}