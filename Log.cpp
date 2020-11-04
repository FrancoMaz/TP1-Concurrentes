//
// Created by francomazzoni on 2/11/20.
//

#include <fstream>
#include "Log.h"

#include "iostream"

using namespace std;

Log::Log(string archivo, bool modoDebug) {
    this->archivo = archivo;
    this->modoDebug = modoDebug;
}

//Se escribe al archivo el primer log (tiene que pisar el archivo si ya existe)
void Log::escribirAArchivo(const string& mensaje, const string& modo, bool primeraVez) {
    if (modo != "DEBUG" || (this->modoDebug && modo == "DEBUG")) {
        ofstream myfile;
        myfile.open(this->archivo);
        myfile << modo << ": " << mensaje << endl;
        myfile.close();
    }
}

//Se escriben los logs restantes (se appendea al archivo ya existente)
void Log::escribirAArchivo(const string& mensaje, const string& modo) {
    if (modo != "DEBUG" || (this->modoDebug && modo == "DEBUG")) {
        ofstream myfile;
        myfile.open(this->archivo, ios_base::app);
        myfile << modo << ": " << mensaje << endl;
        myfile.close();
    }
}