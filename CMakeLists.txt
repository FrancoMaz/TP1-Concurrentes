cmake_minimum_required(VERSION 3.17)
project(Concurrentes)

set(CMAKE_CXX_STANDARD 14)

add_executable(Concurrentes memoria_compartida/main.cpp Camara.cpp Camara.h Imagen.cpp Imagen.h Aplanador.cpp Aplanador.h Pixel.cpp Pixel.h Ajustador.cpp Ajustador.h senial/EventHandler.h senial/SIGINT_handler.h senial/SignalHandler.cpp senial/SignalHandler.h memoria_compartida/MemoriaCompartida.h)
add_executable(ConcurrentesFifos fifos/main.cpp fifos/Fifo.cpp fifos/Fifo.h fifos/FifoEscritura.cpp fifos/FifoLectura.cpp fifos/FifoLectura.h fifos/FifoEscritura.h Camara.cpp Camara.h Imagen.cpp Imagen.h Aplanador.cpp Aplanador.h Pixel.cpp Pixel.h Ajustador.cpp Ajustador.h senial/EventHandler.h senial/SIGINT_handler.h senial/SignalHandler.cpp senial/SignalHandler.h)