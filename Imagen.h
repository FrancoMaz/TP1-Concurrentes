//
// Created by francomazzoni on 24/10/20.
//

#ifndef CONCURRENTES_IMAGEN_H
#define CONCURRENTES_IMAGEN_H

#include "Pixel.h"
#include <vector>

using namespace std;

class Imagen {

private:

    vector<Pixel> pixeles;
    int pixelesImagenes;

public:

    explicit Imagen(int pixelesImagenes);
    ~Imagen();
    static int calcularRandom(int numerosPosibles);

    int  getPixel(int posicion);

    void ajustar(int valor);

    string mostrar() const;

    void agregarPixel(int valor);

    void generarValores();

};


#endif //CONCURRENTES_IMAGEN_H
