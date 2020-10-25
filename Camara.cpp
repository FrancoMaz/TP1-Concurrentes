//
// Created by francomazzoni on 24/10/20.
//

#include "Camara.h"
#include "Imagen.h"

int pixelesImagenes;
Imagen *imagen;

Camara::Camara(int pixelesPorFila) {
    pixelesImagenes = pixelesPorFila;
}

void Camara::generarImagen() {
    imagen = new Imagen(pixelesImagenes);
    imagen->generarValores();
}

void Camara::ajustarImagen() {
    imagen->ajustar(10);
}

void Camara::mostrarImagen() {
    imagen->mostrar();
}

Imagen Camara::getImagen() {
    return *imagen;
}