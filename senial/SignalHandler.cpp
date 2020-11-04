//
// Created by francomazzoni on 27/10/20.
//

#include "SignalHandler.h"

SignalHandler* SignalHandler::instance = nullptr;
EventHandler* SignalHandler::signal_handlers[NSIG];

SignalHandler::SignalHandler() = default;

//Se handlean todas las señales registradas
void SignalHandler::dispatcher(int signum) {
    if (SignalHandler::signal_handlers[signum] != nullptr)
        SignalHandler::signal_handlers[signum]->handleSignal(signum);
}

//Se toma la instancia de SignalHandler, ya que es singleton
SignalHandler *SignalHandler::getInstance() {
    if (instance == nullptr)
        instance = new SignalHandler();

    return instance;
}

//Se destruye el handler
void SignalHandler::destruir() {
    if (instance != nullptr) {
        delete (instance);
        instance = nullptr;
    }
}

//Se registra la señal correspondiente a signum (para este caso solo sería SIGINT)
EventHandler *SignalHandler::registrarHandler(int signum, EventHandler *eh) {
    EventHandler *old_eh = SignalHandler::signal_handlers[signum];
    SignalHandler::signal_handlers[signum] = eh ;
    struct sigaction sa{} ;
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = SignalHandler::dispatcher;
    sigemptyset(&sa.sa_mask);
    sigaddset(&sa.sa_mask, signum);
    sigaction(signum, &sa,nullptr);
    return old_eh ;
}
