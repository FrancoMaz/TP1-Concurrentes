#ifndef FIFOESCRITURA_H_
#define FIFOESCRITURA_H_

#include "Fifo.h"

class FifoEscritura : public Fifo {
public:
	explicit FifoEscritura(const string& nombre);
	~FifoEscritura() override;

	void abrir() override;
	ssize_t escribir(int* buffer, ssize_t buffsize) const;
};

#endif /* FIFOESCRITURA_H_ */
