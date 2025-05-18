//*****************************************************************
// File:   pruebasPila.hpp
// Author: Programación II. Universidad de Zaragoza
// Date:   febrero 2025
// Coms:   Programa pruebasPila.cpp de prueba del trabajo con pilas
//         de datos enteros y del comportamiento de las funciones
//         definidas en el fichero "funcionesPilaEnt.hpp"
//*****************************************************************

#include <iostream>
#include <iomanip>   // Para setw
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

int main() {
    // PRUEBA 1: Apilar primeros primos y mostrarlos
    PilaEnt P;
    vaciar(P);

    const int PRIMOS[] = {
        2,  3,  5,  7, 11, 13, 17, 19, 23, 29,
        31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
        73, 79, 83, 89, 97
    };

    const int NUM = 15;
    for (int i = 0; i < NUM; ++i) {
        apilar(P, PRIMOS[i]);
    }

    cout << "Se han apilado los " << numDatos(P)
         << " primeros números primos:" << endl << endl;
    mostrarPila(P);
    cout << "----------------------------------------" << endl;
    
    mostrarInvertida(P);
    
    cout << "----------------------------------------" << endl;

    // PRUEBA 2: Eliminar elemento por posición desde el fondo e insertar en fondo
    PilaEnt p;
    vaciar(p);

    const int datos[] = {2, 3, 5, 7, 11};  // Fondo -> Cima
    const int num = sizeof(datos) / sizeof(int);

    for (int i = 0; i < num; ++i) {
        apilar(p, datos[i]);
    }

    cout << "Pila original:" << endl;
    mostrarPila(p);
    cout << endl;

    int i = 2;  // Debería eliminar el 3 (2 es el fondo, 3 es posición 2)
    eliminar(p, i);

    cout << "Pila tras eliminar la posición " << i << " desde el fondo:" << endl;
    mostrarPila(p);
    cout << endl;

    cout << "TEST insertarEnFondo: insertamos el 999 en el fondo" << endl;
    insertarEnFondo(p, 999);
    
    cout << "Contenido de la pila tras insertar en el fondo:" << endl;
    mostrarPila(p);
    
    cout << "TEST eliminarFondo: eliminamos el 999 en el fondo" << endl;
    eliminarFondo(p);
    
    cout << "Contenido de la pila tras eliminar en el fondo:" << endl;
    mostrarPila(p);

    return 0;
}
