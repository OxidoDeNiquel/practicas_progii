//*****************************************************************
// File:   pruebasPila.hpp
// Author: Programación II. Universidad de Zaragoza
// Date:   febrero 2025
// Coms:   Programa pruebasPila.cpp de prueba del trabajo con pilas
//         de datos enteros y del comportamiento de las funciones
//         definidas en el fichero "funcionesPilaEnt.hpp"
//*****************************************************************

#include <iostream>
#include <cstring>
#include "funcionesPilaEnt.hpp"

using namespace std;

void inicializarPila(PilaEnt &p, const int datos[], int num) {
    vaciar(p);
    for (int i = 0; i < num; ++i) {
        apilar(p, datos[i]);
    }
}

void mostrarPila(PilaEnt &p, const int anchura = 3) {
    if (estaVacia(p)) {
        cout << "+";
        for (int i = 0; i < anchura; ++i) cout << "-";
        cout << "+" << endl;
        return;
    }

    int valor = p.datos[p.cima];
    desapilar(p);
    cout << "|" << setw(anchura) << valor << "|" << endl;

    mostrarPila(p, anchura);
    apilar(p, valor);
}

// Programa de prueba que ilustra el trabajo con pilas de datos de enteros
int main() {
	/*
    // Define una pila de datos, P, que almacena datos de tipo 'int'
    PilaEnt P;

    // Vacía la pila P
    vaciar(P);

    // PRIMOS almacena los números primeros menores que 100
    const int PRIMOS[] = {
        2,  3,  5,  7, 11, 13, 17, 19, 23, 29,
        31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
        73, 79, 83, 89, 97
    };

    // Apila en P los NUM primeros números primos
    const int NUM = 15;
    for (int i = 1; i <= NUM; ++i) {
        apilar(P, PRIMOS[i-1]);
    }

    // Muestra por pantalla el contenido de P
    cout << "Se han apilado los " << numDatos(P)
         << " primeros numeros primos:" << endl << endl;
    mostrarPila(P);

    // Muestra por pantalla los datos de P en orden inverso
    
    cout << "Y esta es la pila invertida:" << endl << endl;
    mostrarInvertida(P);
	*/
	
	PilaEnt p;
    vaciar(p);

    const int datos[] = {2, 3, 5, 7, 11};  // Fondo -> Cima
    const int num = sizeof(datos) / sizeof(int);

    // Apilar en orden adecuado (cima es el último)
    for (int i = 0; i < num; ++i) {
        apilar(p, datos[i]);
    }

    cout << "Pila original:" << endl;
    mostrarPila(p);
    cout << endl;

    // Eliminar el elemento en posición i (desde el fondo, empezando en 1)
    int i = 2;  // Debería eliminar el 3
    eliminar(p, i);

    cout << "Pila tras eliminar la posición " << i << " desde el fondo:" << endl;
    mostrarPila(p);
    cout << endl;
    
    cout << endl << "TEST insertarEnFondo: insertamos el 999 en el fondo" << endl;

    insertarEnFondo(p, 999);

    cout << "Contenido de la pila tras insertar en el fondo:" << endl;
    mostrarPila(p);
	
    return 0;
}
