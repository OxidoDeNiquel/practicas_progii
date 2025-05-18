//*****************************************************************
// File:   funcionesPilaEnt.cpp
// Author: Programación II. Universidad de Zaragoza
// Date:   febrero 2025
// Coms:   
//*****************************************************************

#include <iomanip> // para setw
#include <iostream>
#include <cstring>
#include "pilaEnt.hpp"

using namespace std;

// * Notación empleada en las especificaciones:
// p = []  La pila p está vacía, es decir, almacena 0 datos
// p = [d_1, d_2, ..., d_K] la pila p almacena K datos. El más antiguo
//     es el dato d_1, el segundo más antiguo el dato d_2, etc., etc.,
//     y el más reciente es el dato d_K

// * Pre:  p = [d_1, d_2, ..., d_K] AND K >= 0
// * Post: p = [d_1, d_2, ..., d_K] AND numDatos(p) = K
int numDatos(PilaEnt &p){
    return p.cima + 1;
}


//Funcion auxiliar para el final de la linea
void imprimirGuiones(const int n) {
    if (n > 0) {
        cout << "-";
        imprimirGuiones(n - 1);
    }
}

// Pre:  p = [d_1, d_2, ..., d_K]  AND K >= 0 AND anchura >= 1
// Post: p = [d_1, d_2, ..., d_K] y presenta por pantalla un listado de
//       los datos apilados en la pila comenzando por la cima, d_K, y acabando
//       por el del fondo de la pila, d_1. Cada dato lo escribe en una línea,
//       empleando anchura caracteres y alineado a la derecha. Cada dato es
//       precedido por el carácter '|' y es seguido por los caracteres ' ' y
//       '|', tal como se  ilustra a continuación. Tras el último dato se
//       presenta una linea de la forma "+--...--+", seguida por una línea
//       en blanco:
//
//        |     d_K |
//        |     ... |
//        |     d_2 |
//        |     d_1 |
//        +---------+
void mostrar(PilaEnt &p, const int anchura=3){
	if(estaVacia(p)){
		cout << "+";
		imprimirGuiones(anchura);
		cout << "+" << endl;
	}else{
	
        int valor = cima(p);
        cout << "|" << setw(anchura) << valor << "|" << endl;

        desapilar(p);            // Desapilamos el valor
        mostrar(p, anchura);     // Llamada recursiva
        apilar(p, valor);        // Recuperamos el estado de la pila
	}
}

// Pre:  p = [d_1, d_2, ..., d_K] AND K >= 0 AND anchura >= 1
// Post: p = [d_1, d_2, ..., d_K] y presenta por pantalla un listado de los
//       datos apilados en la pila comenzando por el del fondo de la pila, d_1,
//       y acabando por el de la cima de la pila, d_K. Cada dato lo escribe
//       en una línea, empleando anchura caracteres y alineado a la derecha.
//       Cada dato es precedido por el carácter '|' y es seguido por los
//       caracteres ' ' y '|', tal como se  ilustra a continuación. Antes
//       del primer dato se presenta una linea de la forma "+--...--+":
//
//        +---------+
//        |     d_1 |
//        |     d_2 |
//        |     ... |
//        |     d_K |
void mostrarInvertida(PilaEnt &p, const int anchura=3){
	if(estaVacia(p)){
		cout << "+";
		imprimirGuiones(anchura);
		cout << "+" << endl;
	}else{
		int valor = cima(p);
		desapilar(p);
		mostrarInvertida(p, anchura);
		cout << "|" << setw(anchura) << valor << "|" << endl;
		apilar(p, valor);
	}
}

// Pre:  p = [d_1, d_2, ..., d_K] AND K >= 0
// Post: p = [d_2, ..., d_K]
void eliminarFondo(PilaEnt &p) {
    int valor = cima(p);
    desapilar(p);

    if (estaVacia(p)) {
        // Hemos llegado al fondo, no volvemos a apilar
        return;
    }

    eliminarFondo(p);  // seguimos descendiendo
    apilar(p, valor);  // volvemos a apilar el resto
}


void eliminar(PilaEnt &pila, const int posicionDesdeFondo) {
    int totalElementos = numDatos(pila);
    if (posicionDesdeFondo < 1 || posicionDesdeFondo > totalElementos) return;  // índice fuera de rango

    int elementoCima = cima(pila);
    desapilar(pila);

    int indiceAEliminar = totalElementos - posicionDesdeFondo;  // índice desde la cima (0-based)
    int elementosDesapilados = totalElementos - numDatos(pila) - 1; // cuántos elementos hemos desapilado antes de este

    if (elementosDesapilados == indiceAEliminar) {
        // Este es el elemento que queremos eliminar, no lo apilamos
        return;
    }

    eliminar(pila, posicionDesdeFondo);
    apilar(pila, elementoCima);
}


// Pre:  p = [d_1, d_2, ..., d_K] AND K >= 0
// Post: p = [nuevo, d_1, d_2, ..., d_K]
void insertarEnFondo(PilaEnt &p, const int nuevo) {
    if (estaVacia(p)) {
        // Hemos llegado al fondo
        apilar(p, nuevo);
        return; // IMPORTANTE: salir de la función
    }

    int valor = cima(p);
    desapilar(p);

    insertarEnFondo(p, nuevo);  // seguimos descendiendo
    apilar(p, valor);  // volvemos a apilar el resto
}
