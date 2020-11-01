#ifndef FIFOLECTURA_H_
#define FIFOLECTURA_H_

#include "Fifo.h"

class FifoLectura : public Fifo {
public:
	explicit FifoLectura(string nombre);
	~FifoLectura() override;

	void abrir() override;
	ssize_t leer(int* buffer, ssize_t buffsize) const;
};

#endif /* FIFOLECTURA_H_ */
