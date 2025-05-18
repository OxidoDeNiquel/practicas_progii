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

all: baldosas
#-----------------------------------------------------------
# Compilacion
baldosas.o: baldosas.cpp
	${CC} -c baldosas.cpp ${CPPFLAGS}

# Linkado
baldosas: baldosas.o
	${CC} baldosas.o -o baldosas

#-----------------------------------------------------------	
# LIMPIEZA de todo lo generado. Ojo: se borrarán sin preguntar
clean:
	${RM} baldosas.o baldosas
