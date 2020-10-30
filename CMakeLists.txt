cmake_minimum_required(VERSION 3.17)
project(Concurrentes)

set(CMAKE_CXX_STANDARD 14)

add_executable(Concurrentes main.cpp Camara.cpp Camara.h Imagen.cpp Imagen.h Aplanador.cpp Aplanador.h Pixel.cpp Pixel.h Ajustador.cpp Ajustador.h senial/EventHandler.h senial/SIGINT_handler.h senial/SignalHandler.cpp senial/SignalHandler.h MemoriaCompartida.h)