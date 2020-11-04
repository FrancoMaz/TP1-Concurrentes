#include "FifoLectura.h"

using namespace std;

FifoLectura::FifoLectura(const string nombre) : Fifo(nombre) {
}

FifoLectura::~FifoLectura() {
}

//Se abre el FIFO para lectura
void FifoLectura::abrir() {
	fd = open(nombre.c_str(),O_RDONLY);
}

//Se leen los datos del FIFO y se devuelve la cantidad de bytes leídos
ssize_t FifoLectura::leer(int* buffer, const ssize_t buffsize) const {
	return read(fd, buffer, buffsize);
}
