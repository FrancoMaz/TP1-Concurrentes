#include "Fifo.h"
#include "iostream"

using namespace std;

Fifo::Fifo(const string& nombre) : nombre(nombre), fd(-1) {
	mknod(static_cast<const char*>(nombre.c_str()),S_IFIFO|0666,0);
}

Fifo::~Fifo() = default;

void Fifo::cerrar() {
	close(fd);
	fd = -1;
}

void Fifo::eliminar() const {
	unlink(nombre.c_str());
}
