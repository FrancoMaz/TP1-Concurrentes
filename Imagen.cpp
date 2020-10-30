//
// Created by francomazzoni on 24/10/20.
//

#include <cstdlib>
#include <iostream>
#include "Imagen.h"

using namespace std;

Imagen::Imagen(int pixelesImagenes) {
    this->pixelesImagenes = pixelesImagenes;
    this->procesada = false;
}

void Imagen::generarValores() {
    for (int i = 0; i < this->pixelesImagenes; i++) {
        pixeles.emplace_back(calcularRandom(100));
    }
}

void Imagen::ajustar(int valor) {
    for (auto & pixel : this->pixeles){
        pixel.ajustar(calcularRandom(valor));
    }
    this->procesada = true;
}

int Imagen::getPixel(int posicion) {
    return this->pixeles[posicion].getValor();
}

int Imagen::calcularRandom(int numerosPosibles) {
    return rand() % numerosPosibles + 1;
}

void Imagen::mostrar() {

    for (auto & pixel : this->pixeles){
        cout << pixel.getValor() << "   ";
    }

    cout << endl;
}

void Imagen::agregarPixel(int valor) {
    pixeles.emplace_back(valor);
}
