# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/francomazzoni/Descargas/CLion-2020.2.4/clion-2020.2.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/francomazzoni/Descargas/CLion-2020.2.4/clion-2020.2.4/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/francomazzoni/TP1-Concurrentes

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/francomazzoni/TP1-Concurrentes/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Concurrentes.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Concurrentes.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Concurrentes.dir/flags.make

CMakeFiles/Concurrentes.dir/memoria_compartida/main.cpp.o: CMakeFiles/Concurrentes.dir/flags.make
CMakeFiles/Concurrentes.dir/memoria_compartida/main.cpp.o: ../memoria_compartida/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/francomazzoni/TP1-Concurrentes/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Concurrentes.dir/memoria_compartida/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Concurrentes.dir/memoria_compartida/main.cpp.o -c /home/francomazzoni/TP1-Concurrentes/memoria_compartida/main.cpp

CMakeFiles/Concurrentes.dir/memoria_compartida/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Concurrentes.dir/memoria_compartida/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/francomazzoni/TP1-Concurrentes/memoria_compartida/main.cpp > CMakeFiles/Concurrentes.dir/memoria_compartida/main.cpp.i

CMakeFiles/Concurrentes.dir/memoria_compartida/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Concurrentes.dir/memoria_compartida/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/francomazzoni/TP1-Concurrentes/memoria_compartida/main.cpp -o CMakeFiles/Concurrentes.dir/memoria_compartida/main.cpp.s

CMakeFiles/Concurrentes.dir/Camara.cpp.o: CMakeFiles/Concurrentes.dir/flags.make
CMakeFiles/Concurrentes.dir/Camara.cpp.o: ../Camara.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/francomazzoni/TP1-Concurrentes/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Concurrentes.dir/Camara.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Concurrentes.dir/Camara.cpp.o -c /home/francomazzoni/TP1-Concurrentes/Camara.cpp

CMakeFiles/Concurrentes.dir/Camara.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Concurrentes.dir/Camara.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/francomazzoni/TP1-Concurrentes/Camara.cpp > CMakeFiles/Concurrentes.dir/Camara.cpp.i

CMakeFiles/Concurrentes.dir/Camara.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Concurrentes.dir/Camara.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/francomazzoni/TP1-Concurrentes/Camara.cpp -o CMakeFiles/Concurrentes.dir/Camara.cpp.s

CMakeFiles/Concurrentes.dir/Imagen.cpp.o: CMakeFiles/Concurrentes.dir/flags.make
CMakeFiles/Concurrentes.dir/Imagen.cpp.o: ../Imagen.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/francomazzoni/TP1-Concurrentes/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Concurrentes.dir/Imagen.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Concurrentes.dir/Imagen.cpp.o -c /home/francomazzoni/TP1-Concurrentes/Imagen.cpp

CMakeFiles/Concurrentes.dir/Imagen.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Concurrentes.dir/Imagen.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/francomazzoni/TP1-Concurrentes/Imagen.cpp > CMakeFiles/Concurrentes.dir/Imagen.cpp.i

CMakeFiles/Concurrentes.dir/Imagen.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Concurrentes.dir/Imagen.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/francomazzoni/TP1-Concurrentes/Imagen.cpp -o CMakeFiles/Concurrentes.dir/Imagen.cpp.s

CMakeFiles/Concurrentes.dir/Aplanador.cpp.o: CMakeFiles/Concurrentes.dir/flags.make
CMakeFiles/Concurrentes.dir/Aplanador.cpp.o: ../Aplanador.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/francomazzoni/TP1-Concurrentes/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Concurrentes.dir/Aplanador.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Concurrentes.dir/Aplanador.cpp.o -c /home/francomazzoni/TP1-Concurrentes/Aplanador.cpp

CMakeFiles/Concurrentes.dir/Aplanador.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Concurrentes.dir/Aplanador.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/francomazzoni/TP1-Concurrentes/Aplanador.cpp > CMakeFiles/Concurrentes.dir/Aplanador.cpp.i

CMakeFiles/Concurrentes.dir/Aplanador.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Concurrentes.dir/Aplanador.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/francomazzoni/TP1-Concurrentes/Aplanador.cpp -o CMakeFiles/Concurrentes.dir/Aplanador.cpp.s

CMakeFiles/Concurrentes.dir/Pixel.cpp.o: CMakeFiles/Concurrentes.dir/flags.make
CMakeFiles/Concurrentes.dir/Pixel.cpp.o: ../Pixel.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/francomazzoni/TP1-Concurrentes/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Concurrentes.dir/Pixel.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Concurrentes.dir/Pixel.cpp.o -c /home/francomazzoni/TP1-Concurrentes/Pixel.cpp

CMakeFiles/Concurrentes.dir/Pixel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Concurrentes.dir/Pixel.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/francomazzoni/TP1-Concurrentes/Pixel.cpp > CMakeFiles/Concurrentes.dir/Pixel.cpp.i

CMakeFiles/Concurrentes.dir/Pixel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Concurrentes.dir/Pixel.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/francomazzoni/TP1-Concurrentes/Pixel.cpp -o CMakeFiles/Concurrentes.dir/Pixel.cpp.s

CMakeFiles/Concurrentes.dir/Ajustador.cpp.o: CMakeFiles/Concurrentes.dir/flags.make
CMakeFiles/Concurrentes.dir/Ajustador.cpp.o: ../Ajustador.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/francomazzoni/TP1-Concurrentes/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Concurrentes.dir/Ajustador.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Concurrentes.dir/Ajustador.cpp.o -c /home/francomazzoni/TP1-Concurrentes/Ajustador.cpp

CMakeFiles/Concurrentes.dir/Ajustador.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Concurrentes.dir/Ajustador.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/francomazzoni/TP1-Concurrentes/Ajustador.cpp > CMakeFiles/Concurrentes.dir/Ajustador.cpp.i

CMakeFiles/Concurrentes.dir/Ajustador.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Concurrentes.dir/Ajustador.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/francomazzoni/TP1-Concurrentes/Ajustador.cpp -o CMakeFiles/Concurrentes.dir/Ajustador.cpp.s

CMakeFiles/Concurrentes.dir/senial/SignalHandler.cpp.o: CMakeFiles/Concurrentes.dir/flags.make
CMakeFiles/Concurrentes.dir/senial/SignalHandler.cpp.o: ../senial/SignalHandler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/francomazzoni/TP1-Concurrentes/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Concurrentes.dir/senial/SignalHandler.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Concurrentes.dir/senial/SignalHandler.cpp.o -c /home/francomazzoni/TP1-Concurrentes/senial/SignalHandler.cpp

CMakeFiles/Concurrentes.dir/senial/SignalHandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Concurrentes.dir/senial/SignalHandler.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/francomazzoni/TP1-Concurrentes/senial/SignalHandler.cpp > CMakeFiles/Concurrentes.dir/senial/SignalHandler.cpp.i

CMakeFiles/Concurrentes.dir/senial/SignalHandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Concurrentes.dir/senial/SignalHandler.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/francomazzoni/TP1-Concurrentes/senial/SignalHandler.cpp -o CMakeFiles/Concurrentes.dir/senial/SignalHandler.cpp.s

CMakeFiles/Concurrentes.dir/Log.cpp.o: CMakeFiles/Concurrentes.dir/flags.make
CMakeFiles/Concurrentes.dir/Log.cpp.o: ../Log.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/francomazzoni/TP1-Concurrentes/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Concurrentes.dir/Log.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Concurrentes.dir/Log.cpp.o -c /home/francomazzoni/TP1-Concurrentes/Log.cpp

CMakeFiles/Concurrentes.dir/Log.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Concurrentes.dir/Log.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/francomazzoni/TP1-Concurrentes/Log.cpp > CMakeFiles/Concurrentes.dir/Log.cpp.i

CMakeFiles/Concurrentes.dir/Log.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Concurrentes.dir/Log.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/francomazzoni/TP1-Concurrentes/Log.cpp -o CMakeFiles/Concurrentes.dir/Log.cpp.s

# Object files for target Concurrentes
Concurrentes_OBJECTS = \
"CMakeFiles/Concurrentes.dir/memoria_compartida/main.cpp.o" \
"CMakeFiles/Concurrentes.dir/Camara.cpp.o" \
"CMakeFiles/Concurrentes.dir/Imagen.cpp.o" \
"CMakeFiles/Concurrentes.dir/Aplanador.cpp.o" \
"CMakeFiles/Concurrentes.dir/Pixel.cpp.o" \
"CMakeFiles/Concurrentes.dir/Ajustador.cpp.o" \
"CMakeFiles/Concurrentes.dir/senial/SignalHandler.cpp.o" \
"CMakeFiles/Concurrentes.dir/Log.cpp.o"

# External object files for target Concurrentes
Concurrentes_EXTERNAL_OBJECTS =

Concurrentes: CMakeFiles/Concurrentes.dir/memoria_compartida/main.cpp.o
Concurrentes: CMakeFiles/Concurrentes.dir/Camara.cpp.o
Concurrentes: CMakeFiles/Concurrentes.dir/Imagen.cpp.o
Concurrentes: CMakeFiles/Concurrentes.dir/Aplanador.cpp.o
Concurrentes: CMakeFiles/Concurrentes.dir/Pixel.cpp.o
Concurrentes: CMakeFiles/Concurrentes.dir/Ajustador.cpp.o
Concurrentes: CMakeFiles/Concurrentes.dir/senial/SignalHandler.cpp.o
Concurrentes: CMakeFiles/Concurrentes.dir/Log.cpp.o
Concurrentes: CMakeFiles/Concurrentes.dir/build.make
Concurrentes: CMakeFiles/Concurrentes.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/francomazzoni/TP1-Concurrentes/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable Concurrentes"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Concurrentes.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Concurrentes.dir/build: Concurrentes

.PHONY : CMakeFiles/Concurrentes.dir/build

CMakeFiles/Concurrentes.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Concurrentes.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Concurrentes.dir/clean

CMakeFiles/Concurrentes.dir/depend:
	cd /home/francomazzoni/TP1-Concurrentes/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/francomazzoni/TP1-Concurrentes /home/francomazzoni/TP1-Concurrentes /home/francomazzoni/TP1-Concurrentes/cmake-build-debug /home/francomazzoni/TP1-Concurrentes/cmake-build-debug /home/francomazzoni/TP1-Concurrentes/cmake-build-debug/CMakeFiles/Concurrentes.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Concurrentes.dir/depend

