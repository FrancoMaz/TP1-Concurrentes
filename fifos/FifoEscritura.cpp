#include "FifoEscritura.h"

using namespace std;

FifoEscritura::FifoEscritura(const string& nombre) : Fifo(nombre) {
}

FifoEscritura::~FifoEscritura() = default;

//Se abre el FIFO para escritura
void FifoEscritura::abrir() {
	fd = open(nombre.c_str(), O_WRONLY);
}

//Se escribe el buffer en el FIFO
ssize_t FifoEscritura::escribir(int* buffer, const ssize_t buffsize) const {
	return write(fd,buffer,buffsize);
}
