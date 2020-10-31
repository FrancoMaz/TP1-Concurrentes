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

template <class T> class MemoriaCompartida {

private:
    int	shmId;
    T*	ptrDatos;

    int	cantidadProcesosAdosados() const;

public:
    MemoriaCompartida();
    MemoriaCompartida (const std::string& archivo,char letra, int arraySize, int memory);
    ~MemoriaCompartida ();
    MemoriaCompartida<T>& operator= ( const MemoriaCompartida& origen );
    void escribir ( const T& dato );
    T leer () const;
};

template <class T> MemoriaCompartida<T>::MemoriaCompartida ():shmId(0),ptrDatos(NULL) {
}

template <class T> MemoriaCompartida<T>::MemoriaCompartida (const string& archivo,const char letra, int size, int memory):shmId(0),ptrDatos(NULL) {
    key_t clave = ftok ( archivo.c_str(),letra );

    if ( clave > 0 ) {
        this->shmId = shmget ( clave,sizeof(int) * size, memory);

        if ( this->shmId > 0 ) {
            void* tmpPtr = shmat ( this->shmId,NULL,0 );
            if ( tmpPtr != (void*) -1 ) {
                this->ptrDatos = static_cast<T*> (tmpPtr);
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

template <class T> MemoriaCompartida<T>::~MemoriaCompartida () {
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

template <class T> MemoriaCompartida<T>& MemoriaCompartida<T>::operator= ( const MemoriaCompartida& origen ) {
    this->shmId = origen.shmId;
    void* tmpPtr = shmat ( this->shmId,NULL,0 );

    if ( tmpPtr != (void*) -1 ) {
        this->ptrDatos = static_cast<T*> (tmpPtr);
    } else {
        string mensaje = string("Error en shmat(): ") + string(strerror(errno));
        throw mensaje;
    }

    return *this;
}

template <class T> void MemoriaCompartida<T>::escribir (const T& dato) {
    *(this->ptrDatos) = dato;
}

template <class T> T MemoriaCompartida<T>::leer() const {
    return *(this->ptrDatos);
}

template <class T> int MemoriaCompartida<T> :: cantidadProcesosAdosados () const {
    shmid_ds estado{};
    shmctl ( this->shmId,IPC_STAT,&estado );
    return estado.shm_nattch;
}

#endif
