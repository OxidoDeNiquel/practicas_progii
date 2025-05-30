//*****************************************************************
// File:   pilaEnt.hpp
// Author: Programación II. Universidad de Zaragoza
// Date:   febrero 2025
// Coms:   Fichero de interfaz del módulo de biblioteca pilaEnt
//*****************************************************************

#ifndef PILAENT_HPP
#define PILAENT_HPP


const int DIM = 256;     // Capacidad máxima de almacenamiento de datos en una pila

// Un dato definido a partir del tipo PilaEnt representa una pila
// de datos de enteros. Los datos son gestionados según una política LIFO,
// es decir el último en ser apilado será el primero en ser desapilado.
struct PilaEnt {
	int datos[DIM]; // array que almacena los elementos
    int cima;       // índice del último elemento apilado (-1 si está vacía)
    
    // Constructor para inicializar
    PilaEnt() : cima(-1) {}
};

//  Notación empleada en la especificación de funciones:
//    p = [] la pila está vacía, es decir, almacena 0 datos
//    p = [d_1, d_2, ..., d_K] la pila almacena K datos. El más antiguo
//        es el dato d_1, el segundo más antiguo el dato d_2, etc., etc.,
//        y el más reciente es el dato d_K

// Pre:  ---
// Post: p = []
void vaciar(PilaEnt &p);

// Pre:  p = [d_1, d_2, ..., d_K] AND K >= 0 AND K < DIM
// Post: p = [d_1, d_2, ..., d_K, nuevo]
void apilar(PilaEnt &p, const int nuevo);

// Pre:  p = [d_1, d_2, ...,d_(K-1), d_K] AND K > 0
// Post: p = [d_1, d_2, ..., d_(K-1)]
void desapilar(PilaEnt &p);

// Pre:  p = [d_1, d_2, ...,d_(K-1),d_K] AND K > 0
// Post: cima(p) = d_K
int cima(const PilaEnt &p);

// Pre: ---
// Post: estaVacia(p) = (p = [])
bool estaVacia(const PilaEnt &p);

// * Pre: p = [d_1, d_2, ..., d_K]
// * Post: estaLlena(p) = (K = DIM])
bool estaLlena(const PilaEnt &p);

#endif
