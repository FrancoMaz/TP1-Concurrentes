//
// Created by francomazzoni on 24/10/20.
//

#ifndef CONCURRENTES_PIXEL_H
#define CONCURRENTES_PIXEL_H


#include <string>

class Pixel {

private:
    int valor;

public:
    explicit Pixel(int valor);

    void ajustar(int valor);

    int getValor() const;
};


#endif //CONCURRENTES_PIXEL_H
