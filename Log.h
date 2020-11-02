//
// Created by francomazzoni on 2/11/20.
//

#ifndef CONCURRENTES_LOG_H
#define CONCURRENTES_LOG_H
#include "iostream"

using namespace std;

class Log {

private:
    string archivo;
    bool modoDebug;

public:
    explicit Log(string archivo, bool modoDebug);
    void escribirAArchivo(const string& mensaje, const string& modo);
};


#endif //CONCURRENTES_LOG_H
