//
// Created by francomazzoni on 27/10/20.
//

#ifndef CONCURRENTES_SIGINT_HANDLER_H
#define CONCURRENTES_SIGINT_HANDLER_H

#include <csignal>
#include <cassert>

#include "EventHandler.h"

class SIGINT_Handler: public EventHandler {
private:
    sig_atomic_t gracefulQuit;
public:
    SIGINT_Handler(): gracefulQuit(0) {}
    ~SIGINT_Handler() override = default;

    //Para SIGINT, se setea el parámetro gracefulQuit en 1 si se detecta la señal (desde el main se valida el valor de ese parámetro)
    int handleSignal(int signum) override {
        assert(signum == SIGINT);
        this->gracefulQuit = 1;
        return 0;
    }

    sig_atomic_t getGracefulQuit() const {
        return this->gracefulQuit;
    }

};

#endif //CONCURRENTES_SIGINT_HANDLER_H
