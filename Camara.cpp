//
// Created by francomazzoni on 24/10/20.
//

#include "Camara.h"
#include "Imagen.h"

Camara::Camara(const Imagen& imagen) : imagen(imagen) {

}

//Se genera la imágen de la cámara
Imagen Camara::generarImagen(int pixelesPorFila) {
    imagen = Imagen(pixelesPorFila * pixelesPorFila);
    imagen.generarValores();
    return imagen;
}