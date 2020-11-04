#include "Fifo.h"
#include "iostream"

using namespace std;

//Se linkea el nombre al FIFO
Fifo::Fifo(const string& nombre) : nombre(nombre), fd(-1) {
	mknod(static_cast<const char*>(nombre.c_str()),S_IFIFO|0666,0);
}

Fifo::~Fifo() = default;

//Se cierra el FIFO
void Fifo::cerrar() {
	close(fd);
	fd = -1;
}

//Se deslinkea el nombre al FIFO
void Fifo::eliminar() const {
	unlink(nombre.c_str());
}
