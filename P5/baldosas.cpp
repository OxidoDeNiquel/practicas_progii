//*****************************************************************
// File:   mayores.cpp
// Author: Programación II. Universidad de Zaragoza
// Date:   marzo 2025
// Coms:   
//*****************************************************************

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX_N = 1024;
int tablero[MAX_N][MAX_N];
int contadorBaldosa = 1;

// Coloca una baldosa con el número del contador en tres celdas dadas
void colocarBaldosa(int r1, int c1, int r2, int c2, int r3, int c3) {
    tablero[r1][c1] = tablero[r2][c2] = tablero[r3][c3] = contadorBaldosa++;
}

// Función recursiva principal para embaldosar el tablero
// r, c: esquina superior izquierda del tablero actual
// tam: tamaño del tablero actual
// ocR, ocC: coordenadas de la celda ya ocupada dentro de este tablero
void embaldosar(int n, char s, int x, int y, int filaOcupada, int columnaOcupada){
	//caso base
	if(n == 2){
		int dx[] = {0, 0, 1, 1};
		int dy[] = {0, 1, 0, 1};
		int pos = 0;
		
        // Celdas a embaldosar (las que no están ocupadas)
        for (int i = 0; i < 4; ++i) {
            if (i != pos)
                tablero[x + dx[i]][y + dy[i]] = contadorBaldosa;
        }
        
        contadorBaldosa++;
        return;
	}
	
	int mid = n / 2;
	
	//Coordenadas de centros de los 4 subtableros
	int subX[4] = {x, x, x + mid, x + mid};
	int subY[4] = {y, y + mid, y, y + mid};
	
	// Índice del cuadrante donde está la celda ocupada
    int quad = (filaOcupada < x + mid ? 0 : 2) + (columnaOcupada < y + mid ? 0 : 1);
    
    // Coordenadas del centro del tablero (donde se colocará la baldosa)
    int centerX = x + mid - 1;
    int centerY = y + mid - 1;
    
    // Coloca la baldosa en el centro, cubriendo las 3 subregiones sin la celda ocupada
    if (quad != 0) tablero[centerX][centerY] = contadorBaldosa;
    if (quad != 1) tablero[centerX][centerY + 1] = contadorBaldosa;
    if (quad != 2) tablero[centerX + 1][centerY] = contadorBaldosa;
    if (quad != 3) tablero[centerX + 1][centerY + 1] = contadorBaldosa;
    contadorBaldosa++;

    // Llamadas recursivas a cada subtablero
    for (int i = 0; i < 4; ++i) {
        int newPosOcupadaX = (i == quad) ? filaOcupada : centerX + (i / 2);
        int newPosOcupadaY = (i == quad) ? columnaOcupada : centerY + (i % 2);
        embaldosar(mid, s, subX[i], subY[i], newPosOcupadaX, newPosOcupadaY);
    }
}

// Imprime el tablero con formato bonito
void imprimirTablero(int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (tablero[i][j] == -1)
                cout << " XX ";
            else
                cout << setw(3) << tablero[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(){
	int n;

    cout << "Introduce el valor de n (potencia de 2, e.g. 2, 4, 8, 16...): ";
    cin >> n;

    if (n <= 0 || (n & (n - 1)) != 0) {
        cout << "Error: n debe ser una potencia de 2 y mayor que 0.\n";
        return 1;
    }

    srand(time(nullptr));

    int ocX = rand() % n;
    int ocY = rand() % n;
    tablero[ocX][ocY] = -1; // Marcamos la celda inicialmente ocupada

    cout << "\nCelda inicialmente ocupada: (" << ocX << ", " << ocY << ")\n\n";

    embaldosar(n, 's', 0, 0, ocX, ocY);

    cout << "Tablero embaldosado:\n";
    imprimirTablero(n);
    
	return 0;
}
