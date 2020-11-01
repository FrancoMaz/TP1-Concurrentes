//
// Created by francomazzoni on 24/10/20.
//

#include "Pixel.h"

Pixel::Pixel(int valorP) {
    this->valor = valorP;
}

void Pixel::ajustar(int valorASumar) {
    this->valor += valorASumar;
}

int Pixel::getValor() const {
    return this->valor;
}

Pixel::~Pixel() = default;
