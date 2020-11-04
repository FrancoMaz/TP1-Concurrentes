# TP1-Concurrentes

Para compilar el ejercicio 1 de Memoria Compartida ingresar por terminal el siguiente comando:

` g++ memoria_compartida/main.cpp Camara.cpp Camara.h Imagen.cpp Imagen.h Aplanador.cpp Aplanador.h Pixel.cpp Pixel.h Ajustador.cpp Ajustador.h senial/EventHandler.h senial/SIGINT_handler.h senial/SignalHandler.cpp senial/SignalHandler.h memoria_compartida/MemoriaCompartida.h Log.cpp Log.h -o output_memoria_compartida.out`

Para ejecutar el ejericio, ingresar:

`./output_memoria_compartida.out`

Para compilar el ejercicio 2 de FIFOs, ingresar:

`g++ fifos/main.cpp fifos/Fifo.cpp fifos/Fifo.h fifos/FifoEscritura.cpp fifos/FifoLectura.cpp fifos/FifoLectura.h fifos/FifoEscritura.h Camara.cpp Camara.h Imagen.cpp Imagen.h Aplanador.cpp Aplanador.h Pixel.cpp Pixel.h Ajustador.cpp Ajustador.h senial/EventHandler.h senial/SIGINT_handler.h senial/SignalHandler.cpp senial/SignalHandler.h Log.cpp Log.h -o output_fifos.out`

Para ejecutarlo, ingresar:

`./output_fifos.out`