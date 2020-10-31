//
// Created by francomazzoni on 27/10/20.
//

#include "SignalHandler.h"

SignalHandler* SignalHandler::instance = nullptr;
EventHandler* SignalHandler::signal_handlers[NSIG];

SignalHandler::SignalHandler() = default;

void SignalHandler::dispatcher(int signum) {
    if (SignalHandler::signal_handlers[signum] != nullptr)
        SignalHandler::signal_handlers[signum]->handleSignal(signum);
}

SignalHandler *SignalHandler::getInstance() {
    if (instance == nullptr)
        instance = new SignalHandler();

    return instance;
}

void SignalHandler::destruir() {
    if (instance != nullptr) {
        delete (instance);
        instance = nullptr;
    }
}

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

int SignalHandler::removerHandler(int signum) {
    SignalHandler::signal_handlers[signum] = nullptr;
    return 0;
}