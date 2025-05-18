//*****************************************************************
// File:   baldosas.cpp
// Author: Programación II. Universidad de Zaragoza
// Date:   marzo 2025
// Coms:   
//*****************************************************************

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MAX_TAMANIO = 1024;
int idBaldosaActual = 1;

// Imprime el tablero por pantalla
void mostrarTablero(int** tablero, int tamanio) {
    for (int fila = 0; fila < tamanio; fila++) {
        for (int columna = 0; columna < tamanio; columna++) {
            cout.width(3);
            cout << tablero[fila][columna];
        }
        cout << endl;
    }
}

// Coloca una baldosa en forma de L en las 3 celdas alrededor del hueco
void colocarBaldosaL(int** tablero, int filaInicio, int colInicio, int huecoFila, int huecoCol) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (filaInicio + i != huecoFila || colInicio + j != huecoCol) {
                tablero[filaInicio + i][colInicio + j] = idBaldosaActual;
            }
        }
    }
    idBaldosaActual++;
}

// Algoritmo recursivo para resolver el embaldosado
void resolverEmbaldosado(int** tablero, int filaInicio, int colInicio, int tamanio, int huecoFila, int huecoCol) {
    if (tamanio == 2) {
        colocarBaldosaL(tablero, filaInicio, colInicio, huecoFila, huecoCol);
        return;
    }

    int mitad = tamanio / 2;
    int filaCentro = filaInicio + mitad;
    int colCentro = colInicio + mitad;

    // Coordenadas de los huecos ficticios para los subtableros
    int huecosFila[4] = {filaCentro - 1, filaCentro - 1, filaCentro, filaCentro};
    int huecosCol[4] = {colCentro - 1, colCentro,     colCentro - 1, colCentro};

    // Determina en qué cuadrante está el hueco real (0 = sup izq, 1 = sup der, 2 = inf izq, 3 = inf der)
    int cuadranteHueco = (huecoFila >= filaCentro) * 2 + (huecoCol >= colCentro);

    // Coloca la baldosa en el centro del tablero (en los tres cuadrantes que NO tienen el hueco real)
    for (int i = 0; i < 4; i++) {
        if (i != cuadranteHueco) {
            tablero[huecosFila[i]][huecosCol[i]] = idBaldosaActual;
        }
    }
    idBaldosaActual++;

    // Llamadas recursivas para cada uno de los 4 subtableros
    for (int i = 0; i < 4; i++) {
        int nuevaFilaInicio = filaInicio + (i / 2) * mitad;
        int nuevaColInicio = colInicio + (i % 2) * mitad;

        int nuevaHuecoFila = (i == cuadranteHueco) ? huecoFila : huecosFila[i];
        int nuevaHuecoCol = (i == cuadranteHueco) ? huecoCol : huecosCol[i];

        resolverEmbaldosado(tablero, nuevaFilaInicio, nuevaColInicio, mitad, nuevaHuecoFila, nuevaHuecoCol);
    }
}

// Verifica si un número es potencia de 2
bool esPotenciaDe2(int n) {
    return n >= 2 && (n & (n - 1)) == 0;
}

// Ejecuta todo el proceso del embaldosado
void ejecutarEmbaldosado(int tamanio, bool mostrar) {
    if (!esPotenciaDe2(tamanio) || tamanio > MAX_TAMANIO) {
        cerr << "El tamaño debe ser potencia de 2 y menor o igual a " << MAX_TAMANIO << endl;
        exit(2);
    }

    srand(time(0));
    int huecoFila = rand() % tamanio;
    int huecoCol = rand() % tamanio;

    // Reserva de memoria dinámica para el tablero
    int** tablero = new int*[tamanio];
    for (int i = 0; i < tamanio; i++) {
        tablero[i] = new int[tamanio]();
    }

    // Marcamos la celda que ya está ocupada
    tablero[huecoFila][huecoCol] = -1;

    resolverEmbaldosado(tablero, 0, 0, tamanio, huecoFila, huecoCol);

    if (mostrar) {
        cout << "Celda ocupada: (" << huecoFila << ", " << huecoCol << ")\n\n";
        mostrarTablero(tablero, tamanio);
    }
	
	//Limpieza
    for (int i = 0; i < tamanio; i++) delete[] tablero[i];
    delete[] tablero;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Uso: " << argv[0] << " <tamaño> [S]" << endl;
        return 1;
    }

    int tamanio = atoi(argv[1]);
    bool mostrar = (argc == 3 && argv[2][0] == 'S');
    ejecutarEmbaldosado(tamanio, mostrar);

    return 0;
}
