#------------------------------------------------------------------------------
# File:   Makefile
# Author: Programación II-Unizar
# Date:   febrero 2025
# Coms:   Ejemplo de Makefile para la práctica 3 de Programación II
#------------------------------------------------------------------------------

#---------------------------------------------------------
# Definición de macros
CC = g++                   # compilador
CPPFLAGS = -std=c++11      # opciones de compilación
RM = rm -f                 # comando para borrar ficheros

all: pruebasPila
#-----------------------------------------------------------
# Compilacion
pruebasPila.o: pruebasPila.cpp
	${CC} -c pruebasPila.cpp -I ../funciones ${CPPFLAGS}
funcionesPilaEnt.o: funcionesPilaEnt.cpp funcionesPilaEnt.hpp
	${CC} -c funcionesPilaEnt.cpp -I ../funciones ${CPPFLAGS}
pilaEnt.o: ../funciones/pilaEnt.cpp ../funciones/pilaEnt.hpp
	${CC} -c ../funciones/pilaEnt.cpp -I ../funciones ${CPPFLAGS}

# Linkado
pruebasPila: pruebasPila.o funcionesPilaEnt.o pilaEnt.o
	${CC} pruebasPila.o funcionesPilaEnt.o pilaEnt.o -I ../funciones -o pruebasPila

#-----------------------------------------------------------	
# LIMPIEZA de todo lo generado. Ojo: se borrarán sin preguntar
clean:
	${RM} pilaEnt.o funcionesPilaEnt.o pruebasPila.o pruebasPila
