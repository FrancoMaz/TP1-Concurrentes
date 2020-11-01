//
// Created by francomazzoni on 24/10/20.
//

#include "Camara.h"
#include "Imagen.h"

Camara::Camara(const Imagen& imagen) : imagen(imagen) {

}

Imagen Camara::generarImagen(int pixelesPorFila) {
    imagen = Imagen(pixelesPorFila * pixelesPorFila);
    imagen.generarValores();
    return imagen;
}

void Camara::ajustarImagen() {
    imagen.ajustar(10);
}

void Camara::mostrarImagen() {
    imagen.mostrar();
}

Imagen Camara::getImagen() {
    return imagen;
}