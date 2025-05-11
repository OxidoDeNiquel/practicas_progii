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
int mayoresR(){
	int numero;
	
	cout << "Diseño recursivo . Introduce una secuencia de enteros :\n";
	cin >> numero;
	
	if(numero < 0){
		return numero;
	}
	
	int negativoAK = mayoresR();
	if(numero > -negativoAK){
		cout << numero << " ";
	}
	
	return negativoAK;
}

// Pre: De la entrada estándar se puede leer una secuencia de
//enteros: a1 , a2 , . . . , ak tal que ak < 0 ∧ ∀i ∈ [1, k−1].ai ≥ 0.
// Post: Escribe por la salida estándar (en cualquier orden) todos
//los enteros ai tal que i < k ∧ ai > −ak . Devuelve ak .
int mayoresI(){
	const int MAX = 1000; // Tamaño máximo por seguridad
    int valores[MAX];
    int n = 0;

    int x;
    cin >> x;

    // Leer valores hasta encontrar uno negativo
    while (x >= 0 && n < MAX) {
        valores[n++] = x;
        cin >> x;
    }

    int ultimo = x;

    // Mostrar valores mayores que -ultimo
    for (int i = 0; i < n; ++i) {
        if (valores[i] > -ultimo) {
            cout << valores[i] << endl;
        }
    }

    return ultimo;
}

int main(){
	cout << "Diseño recursivo. Introduce una secuencia de enteros:" << endl;

	int ultimo = mayoresR();

	cout << endl << "El último entero es: " << ultimo << endl;
	
	cout << "Diseño iterativo. Introduce una secuencia de enteros:" << endl;

	int ultimo = mayoresI();

	cout << endl << "El último entero es: " << ultimo << endl;
		
	return 0;
}
