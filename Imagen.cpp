//
// Created by francomazzoni on 24/10/20.
//

#include <cstdlib>
#include <iostream>
#include "Imagen.h"

using namespace std;

Imagen::Imagen(int pixelesImagenes) {
    this->pixelesImagenes = pixelesImagenes;
}

//Se generan valores aleatorios de 0 a 100
void Imagen::generarValores() {
    for (int i = 0; i < this->pixelesImagenes; i++) {
        pixeles.emplace_back(calcularRandom(100));
    }
}

//Se ajustan todos los pixeles de la imagen
void Imagen::ajustar(int valor) {
    for (auto & pixel : this->pixeles){
        pixel.ajustar(calcularRandom(valor));
    }
}

//Se obtiene un determinado píxel dada la posición dentro del vector
int Imagen::getPixel(int posicion) {
    return this->pixeles[posicion].getValor();
}

//Algoritmo para calcular un número aleatorio
int Imagen::calcularRandom(int numerosPosibles) {
    return rand() % numerosPosibles + 1;
}

//Se devuelve un string con los píxeles de la imagen
string Imagen::mostrar() const {

    string str;
    for (auto & pixel : this->pixeles){
        str += to_string(pixel.getValor());
        str += " ";
    }

    return str;
}

//Se agrega un nuevo píxel
void Imagen::agregarPixel(int valor) {
    pixeles.emplace_back(valor);
}

Imagen::~Imagen() = default;
