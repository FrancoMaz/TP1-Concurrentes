//
// Created by francomazzoni on 27/10/20.
//

#ifndef CONCURRENTES_SIGNALHANDLER_H
#define CONCURRENTES_SIGNALHANDLER_H

#include <csignal>
#include <cstdio>
#include <memory.h>

#include "EventHandler.h"
class SignalHandler {
private:
    static SignalHandler* instance;
    static EventHandler* signal_handlers[NSIG];
    SignalHandler();
    static void dispatcher (int signum);
public:
    static SignalHandler *getInstance();
    static void destruir();
    static EventHandler *registrarHandler (int signum, EventHandler *eh);
};

#endif //CONCURRENTES_SIGNALHANDLER_H
