//*****************************************************************
// File:   pruebasCal.cpp
// Author: Programación II. Universidad de Zaragoza
// Date:   febrero 2025
// Coms:   Programa de pruebas del comportamiento de las funciones
//         definidas en el módulo calculos
//*****************************************************************

#include <iostream>
#include "calculos.hpp"

using namespace std;


// Pre:  <cifras> es el número de cifras de <n> cuando se escribe en base <b>
//       y <b> está comprendido entre 2 y 10
// Post: Informa si el valor devuelto al ejecutar numCifras(n, b) es igual
//       a <cifras> o no lo es
void probarNumCifras(const int n, const int b, const int cifras){
    int r = numCifras(n, b);
    if (r == cifras) {
        cout << "Ok. numCifras(" << n << "," << b << ") = " << r << endl;
    } else {
        cout << "Mal. numCifras(" << n << "," << b << ") = " << r << ", pero debería ser "
             << cifras << endl;
    }
}

// Prueba el comportamiento de numCifras(n,10) para los siguientes valores de n:
// 0, 1, 9, 10, 99, 100, 999, 1000, ... , 99999, 100000, 99999 y 1000000
// y prueba el comportamiento de numCifras(n,2) para los siguientes valores de n:
// 0, 1, 1, 2, 3, 4, 7, 8, 15, 16, 31, 32, ..., 4095, 4096, 8191 y 8192
void probarNumCifras(){
    // Prueba el comportamiento de numCifras(n) para los siguientes valores de n:
    // 0, 1, 9, 10, 99, 100, 999, 1000, ..., 99999, 100000, 99999 y 1000000
    probarNumCifras(0, 10, 1);
    probarNumCifras(1, 10, 1);
    int n = 10;
    int cifras = 2;
    while (n <= 1000000) {
        probarNumCifras(n-1, 10, cifras-1);
        probarNumCifras(n, 10, cifras);
        n = 10*n;
        cifras = cifras + 1;
    }
    cout << endl;
    // Prueba el comportamiento de numCifras(n,2) para los siguientes valores de n:
    // 0, 1, 1, 2, 3, 4, 7, 8, 15, 16, 31, 32, ..., 4095, 4096, 8191 y 8192
    probarNumCifras(0, 2, 1);
    probarNumCifras(1, 2, 1);
    n = 2;
    cifras = 2;
    while (n <= 10000) {
        probarNumCifras(n-1, 2, cifras-1);
        probarNumCifras(n, 2, cifras);
        n = 2 * n;
        cifras = cifras + 1;
    }
    cout << endl;
}

// Pre: Espera que `esperada` sea la i-ésima cifra desde la derecha de n en base b
// Post: Informa si el valor devuelto por cifra(n, i, b) es correcto
void probarCifra(const int n, const int i, const int b, const int esperada) {
    int r = cifra(n, i, b);
    if (r == esperada) {
        cout << "Ok. cifra(" << n << "," << i << "," << b << ") = " << r << endl;
    } else {
        cout << "Mal. cifra(" << n << "," << i << "," << b << ") = " << r
             << ", pero debería ser " << esperada << endl;
    }
}

void probarCifras() {
    // Base 10
    probarCifra(54321, 1, 10, 1);  // unidad
    probarCifra(54321, 2, 10, 2);  // decena
    probarCifra(54321, 3, 10, 3);  // centena
    probarCifra(54321, 4, 10, 4);  // millar
    probarCifra(54321, 5, 10, 5);  // decena de millar

    // Base 2
    // 13 en binario es 1101 → cifra 1 = 1, cifra 2 = 0, cifra 3 = 1, cifra 4 = 1
    probarCifra(13, 1, 2, 1);
    probarCifra(13, 2, 2, 0);
    probarCifra(13, 3, 2, 1);
    probarCifra(13, 4, 2, 1);

    // Base 8
    // 83 en base 8 es 123 → cifra 1 = 3, cifra 2 = 2, cifra 3 = 1
    probarCifra(83, 1, 8, 3);
    probarCifra(83, 2, 8, 2);
    probarCifra(83, 3, 8, 1);
}

void testCifraMayor(const int n, const int b, const int esperada){
    int r = cifraMayor(n, b);
    if (r == esperada) {
        cout << "Ok. cifra(" << n << "," << b << ") = " << r << endl;
    } else {
        cout << "Mal. cifra(" << n << "," << b << ") = " << r
             << ", pero debería ser " << esperada << endl;
    }
	
}

// Prueba el comportamiento de cifraMayor(n,b) para diferentes números naturales
// en las bases de numeración 2, 8 y 10
void probarCifraMayor() {
    // Base 10
    testCifraMayor(0, 10, 0);        // 0
    testCifraMayor(5, 10, 5);        // 5
    testCifraMayor(123, 10, 3);      // 1, 2, 3
    testCifraMayor(90817, 10, 9);    // 9, 0, 8, 1, 7
    testCifraMayor(456789, 10, 9);   // máximo dígito es 9

    // Base 2
    testCifraMayor(5, 2, 1);         // binario: 101 → máximo dígito 1
    testCifraMayor(10, 2, 1);        // 1010 → 1
    testCifraMayor(255, 2, 1);       // 11111111 → 1
    testCifraMayor(256, 2, 1);       // 100000000 → 1

    // Base 8
    testCifraMayor(83, 8, 3);        // 123 → máximo dígito 3
    testCifraMayor(511, 8, 7);       // 777
    testCifraMayor(64, 8, 1);        // 100

    cout << endl;
}

void testCifraMasSignificativa(const int n, const int b, const int esperado) {
    int resultado = cifraMasSignificativa(n, b);
    if (resultado == esperado) {
        cout << "Ok. cifraMasSignificativa(" << n << ", " << b << ") = " << resultado << endl;
    } else {
        cout << "Mal. cifraMasSignificativa(" << n << ", " << b << ") = " << resultado
             << ", pero debería ser " << esperado << endl;
    }
}

// Prueba el comportamiento de cifraMasSignificativa(n,b) para diferentes números naturales
// en las bases de numeración 2, 8 y 10
void probarCifraMasSignificativa(){
    // Código a implementar en la práctica
    // Base 10
    testCifraMasSignificativa(0, 10, 0);
    testCifraMasSignificativa(7, 10, 7);
    testCifraMasSignificativa(42, 10, 4);
    testCifraMasSignificativa(90817, 10, 9);
    testCifraMasSignificativa(123456, 10, 1);
    testCifraMasSignificativa(999999, 10, 9);

    // Base 2
    testCifraMasSignificativa(1, 2, 1);
    testCifraMasSignificativa(2, 2, 1);
    testCifraMasSignificativa(3, 2, 1);
    testCifraMasSignificativa(4, 2, 1);
    testCifraMasSignificativa(5, 2, 1);
    testCifraMasSignificativa(255, 2, 1);
    testCifraMasSignificativa(1024, 2, 1);

    // Base 8
    testCifraMasSignificativa(64, 8, 1);  // 100 en base 8
    testCifraMasSignificativa(511, 8, 7); // 777 en base 8
    testCifraMasSignificativa(512, 8, 1); // 1000 en base 8
}


// Prueba el comportamiento de probarSumaCifras(n,b) para diferentes números naturales
// en las bases de numeración 2, 8 y 10
void probarSumaCifras(const int n, const int b, const int esperado) {
    int resultado = sumaCifras(n, b);
    if (resultado == esperado) {
        cout << "Ok. sumaCifras(" << n << ", " << b << ") = " << resultado << endl;
    } else {
        cout << "Mal. sumaCifras(" << n << ", " << b << ") = " << resultado
             << ", pero debería ser " << esperado << endl;
    }
}

void probarSumaCifras() {
    // Base 10
    probarSumaCifras(0, 10, 0);
    probarSumaCifras(5, 10, 5);
    probarSumaCifras(12, 10, 3);       // 1 + 2
    probarSumaCifras(123, 10, 6);      // 1 + 2 + 3
    probarSumaCifras(999, 10, 27);     // 9 + 9 + 9

    // Base 2
    probarSumaCifras(0, 2, 0);
    probarSumaCifras(1, 2, 1);
    probarSumaCifras(2, 2, 1);         // 10
    probarSumaCifras(5, 2, 2);         // 101
    probarSumaCifras(15, 2, 4);        // 1111
    probarSumaCifras(255, 2, 8);       // 11111111

    // Base 8
    probarSumaCifras(8, 8, 1);         // 10
    probarSumaCifras(15, 8, 8);        // 17 → 1 + 7
    probarSumaCifras(64, 8, 1);        // 100 → 1+0+0
    probarSumaCifras(73, 8, 3);       // 111 → 1+1+1 (error corregido)
    probarSumaCifras(511, 8, 21);      // 777 → 7+7+7
}


// Ejecuta una secuencia de pruebas de las funciones definidas en el módulo calculos.hpp
int main() {
    // Pruebas del comportamiento de numCifras(n,b)
    probarNumCifras();
    // Pruebas del comportamiento de cifra(n,i,b)
    probarCifras();    
    // Pruebas del comportamiento de cifraMayor(n,b)
    probarCifraMayor();    
    // Pruebas del comportamiento de cifraMasSignificativa(n,b)
    probarCifraMasSignificativa();
    // Pruebas del comportamiento de sumaCifras(n,b)
    probarSumaCifras();

    return 0;
}
