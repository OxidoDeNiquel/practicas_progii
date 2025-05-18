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

all: mayores
#-----------------------------------------------------------
# Compilacion
mayores.o: mayores.cpp
	${CC} -c mayores.cpp -I ../funciones ${CPPFLAGS}

pilaEnt.o: ../funciones/pilaEnt.cpp ../funciones/pilaEnt.hpp
	${CC} -c ../funciones/pilaEnt.cpp -I ../funciones ${CPPFLAGS}

# Linkado
mayores: mayores.o pilaEnt.o
	${CC} mayores.o pilaEnt.o -o mayores

#-----------------------------------------------------------	
# LIMPIEZA de todo lo generado. Ojo: se borrarán sin preguntar
clean:
	${RM} mayores.o pilaEnt.o mayores
