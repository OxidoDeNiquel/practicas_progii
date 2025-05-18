//*****************************************************************
// File:   mayores.cpp
// Author: Programación II. Universidad de Zaragoza
// Date:   marzo 2025
// Coms:   
//*****************************************************************

#include <iostream>
#include <cstring>
#include "pilaEnt.hpp"

using namespace std;

// Pre: De la entrada estándar se puede leer una secuencia de
//enteros: a1 , a2 , . . . , ak tal que ak < 0 ∧ ∀i ∈ [1, k−1].ai ≥ 0.
// Post: Escribe por la salida estándar (en cualquier orden) todos
//los enteros ai tal que i < k ∧ ai > −ak . Devuelve ak .
int mayoresR() {
    int num;
    cin >> num;

    if (num < 0) {
        return num;
    } else {
        int ultimo = mayoresR();
        if (num > -ultimo) {
            cout << num << " ";
        }
        return ultimo;
    }
}

// Pre: De la entrada estándar se puede leer una secuencia de
//enteros: a1 , a2 , . . . , ak tal que ak < 0 ∧ ∀i ∈ [1, k−1].ai ≥ 0.
// Post: Escribe por la salida estándar (en cualquier orden) todos
//los enteros ai tal que i < k ∧ ai > −ak . Devuelve ak .

int mayoresI() {
    PilaEnt pila;
    int num;

    // Leer hasta encontrar un negativo
    while (true) {
        cin >> num;
        if (num < 0) break;
        apilar(pila, num);
    }

    // Mostrar los números mayores que el valor absoluto del negativo leído
    int umbral = -num;
    while (!estaVacia(pila)) {
        int cimaVal = cima(pila);
        if (cimaVal > umbral) {
            cout << cimaVal << " ";
        }
        desapilar(pila);
    }
    cout << endl;

    return num;  // devuelve el número negativo final
}

int main() {
    cout << "Diseño recursivo. Introduce una secuencia de enteros:" << endl;
    int ultimoR = mayoresR();
    cout << endl << "El último entero es: " << ultimoR << endl;

    cout << "Diseño iterativo. Introduce una secuencia de enteros:" << endl;
    int ultimoI = mayoresI();
    cout << endl << "El último entero es: " << ultimoI << endl;

    return 0;
}

