//*****************************************************************
// File:   pruebasPila.cpp
// Author: Programación II. Universidad de Zaragoza
// Date:   febrero 2025
// Coms:   Programa pruebasPila.cpp de prueba del trabajo con pilas
//         de datos enteros y del comportamiento de las funciones
//         definidas en el fichero "funcionesPilaEnt.hpp"
//*****************************************************************

#include <iostream>
#include <cstring>
#include "pilaEnt.hpp"

using namespace std;

// Pre:  ---
// Post: p = []
void vaciar(PilaEnt &p){
	p.cima = -1;
}

// Pre:  p = [d_1, d_2, ..., d_K] AND K >= 0 AND K < DIM
// Post: p = [d_1, d_2, ..., d_K, nuevo]
void apilar(PilaEnt &p, const int nuevo){
	if(!estaLlena(p)){
		p.cima++;
		p.datos[p.cima] = nuevo;
	}else{
		cout << "Error: pila llena" << endl;
	}
}

// Pre:  p = [d_1, d_2, ...,d_(K-1), d_K] AND K > 0
// Post: p = [d_1, d_2, ..., d_(K-1)]
void desapilar(PilaEnt &p){
	if(!estaVacia(p)){
		p.cima--;
	}else{
		cout << "Error: pila vacia" << endl;
	}
}

// Pre:  p = [d_1, d_2, ...,d_(K-1),d_K] AND K > 0
// Post: cima(p) = d_K
int cima(const PilaEnt &p){
	if(!estaVacia(p)){
		return p.cima;
	}else{
		return -1;
	}
}

// Pre: ---
// Post: estaVacia(p) = (p = [])
bool estaVacia(const PilaEnt &p){
	return p.cima == -1;
}

// * Pre: p = [d_1, d_2, ..., d_K]
// * Post: estaLlena(p) = (K = DIM])
bool estaLlena(const PilaEnt &p){
	return p.cima == DIM-1;
}
