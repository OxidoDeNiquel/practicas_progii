//*****************************************************************
// File:   listarArgumentos.cpp
// Author: Programaci�n II. Universidad de Zaragoza
// Date:   enero 2025
// Coms:   Programa que lista los argumentos de la l�nea de �rdenes
//*****************************************************************

#include <iostream>

using namespace std;

// Pre: ---
// Post: Presenta por la salida estandar un listado en el que se numeran
//       los argumentos presentes en la linea de �rdenes
int main(int numArg, char* args[]) {
    for (int i = 0; i < numArg; ++i) {
        cout << i+1 << ". " << args[i] << endl;
    }
    return 0;
}
