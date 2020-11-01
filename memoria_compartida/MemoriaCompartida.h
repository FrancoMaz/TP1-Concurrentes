//
// Created by francomazzoni on 30/10/20.
//

#ifndef MEMORIACOMPARTIDA2_H_
#define MEMORIACOMPARTIDA2_H_

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string>
#include <cstring>
#include <iostream>
#include <cerrno>

using namespace std;

class MemoriaCompartida {

private:
    int	shmId;
    int* ptrDatos;

    int	cantidadProcesosAdosados() const;

public:
    MemoriaCompartida();
    MemoriaCompartida (const std::string& archivo,char letra, int arraySize);
    ~MemoriaCompartida ();
    MemoriaCompartida& operator= ( const MemoriaCompartida& origen );
    void escribir ( const int* dato, int offset, int pixelesPorFila );
    int* leer (int offset, int pixelesPorFila) const;
};

MemoriaCompartida::MemoriaCompartida ():shmId(0),ptrDatos(NULL) {
}

MemoriaCompartida::MemoriaCompartida (const string& archivo,const char letra, int size):shmId(0),ptrDatos(NULL) {
    key_t clave = ftok ( archivo.c_str(),letra );

    if ( clave > 0 ) {
        this->shmId = shmget ( clave,sizeof(int) * size,0644|IPC_CREAT );

        if ( this->shmId > 0 ) {
            void* tmpPtr = shmat ( this->shmId,NULL,0 );
            if ( tmpPtr != (void*) -1 ) {
                this->ptrDatos = (int*) tmpPtr;
            } else {
                string mensaje = string("Error en shmat(): ") + string(strerror(errno));
                throw mensaje;
            }
        } else {
            string mensaje = string("Error en shmget(): ") + string(strerror(errno));
            throw mensaje;
        }
    } else {
        string mensaje = string("Error en ftok(): ") + string(strerror(errno));
        throw mensaje;
    }
}

MemoriaCompartida::~MemoriaCompartida () {
    int errorDt = shmdt ( static_cast<void*> (this->ptrDatos) );

    if ( errorDt != -1 ) {
        int procAdosados = this->cantidadProcesosAdosados ();
        if ( procAdosados == 0 ) {
            shmctl ( this->shmId,IPC_RMID,NULL );
        }
    } else {
        cerr << "Error en shmdt(): " << strerror(errno) << endl;
    }
}

MemoriaCompartida& MemoriaCompartida::operator= ( const MemoriaCompartida& origen ) {
    this->shmId = origen.shmId;
    void* tmpPtr = shmat ( this->shmId,NULL,0 );

    if ( tmpPtr != (void*) -1 ) {
        this->ptrDatos = static_cast<int*> (tmpPtr);
    } else {
        string mensaje = string("Error en shmat(): ") + string(strerror(errno));
        throw mensaje;
    }

    return *this;
}

void MemoriaCompartida::escribir (const int* dato, int offset, int arraySize) {

    int contador = 0;
    for (int i = offset; i < arraySize + offset; i++) {
        *(this->ptrDatos + i*sizeof(int)) = dato[contador];
        contador++;
    }
}

int* MemoriaCompartida::leer(int offset, int arraySize) const {
    int* aDevolver = new int[arraySize];
    int contador = 0;
    for (int i = offset; i < arraySize + offset; i++) {
        aDevolver[contador] = *(this->ptrDatos + i*sizeof(int));
        contador++;
    }
    return aDevolver;
}

int MemoriaCompartida:: cantidadProcesosAdosados () const {
    shmid_ds estado{};
    shmctl ( this->shmId,IPC_STAT,&estado );
    return estado.shm_nattch;
}

#endif
