#include "FifoEscritura.h"

using namespace std;

FifoEscritura::FifoEscritura(const string& nombre) : Fifo(nombre) {
}

FifoEscritura::~FifoEscritura() = default;

void FifoEscritura::abrir() {
	fd = open(nombre.c_str(), O_WRONLY);
}

ssize_t FifoEscritura::escribir(void* buffer, const ssize_t buffsize) const {
	return write(fd,buffer,buffsize);
}
