//
// Created by francomazzoni on 27/10/20.
//

#ifndef CONCURRENTES_EVENTHANDLER_H
#define CONCURRENTES_EVENTHANDLER_H

class EventHandler {

public :
    virtual int handleSignal(int signum) = 0;
    virtual ~EventHandler() = default;;
};

#endif //CONCURRENTES_EVENTHANDLER_H
