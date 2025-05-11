#include <iostream>
#include <ctime>
#include <cstdlib>
#include "genNum.hpp"

using namespace std;
// Pre: a ≤ b ∧ b − a ≤ RAND MAX donde a y b son los dos primeros argumentos
// Post: Escribe un entero pseudoaleatorio en el intervalo [a, b]
int main(int argc, char* argv[]) {
	if (argc == 5) {
		//Asignar variables
		char tipo = argv[1][0];  // Tomar el primer carácter de la cadena
		int numeroReg = atoi(argv[2]);  // Convertir string a int
		
		//Guard conditions
		if(tipo == 'E'){
		
			int a = atoi(argv[3]);
			int b = atoi(argv[4]);
			
		}else if(tipo == 'R'){
		
			double a = atof(argv[3]);
			double b = atof(argv[4]);
			
		}else{
			cout << "El primer parámetro debe ser E o R" << endl;
			return 0;
		}
		
		if(numeroReg<=0){
			cout << "El segundo parámetro debe ser mayor que 0" << endl;
			return 0;
		}
		
		//Logica
		if(tipo == 'E'){
		
			int a = atoi(argv[3]);
			int b = atoi(argv[4]);
			
			for(int i = 0; i < numeroReg; i++){
				cout << randInt(a,b) << "\t";
			}
			
		}else{
		
			double a = atof(argv[3]);
			double b = atof(argv[4]);
			
			for(int i = 0; i < numeroReg; i++){
				cout << randDouble(a,b) << "\t";
			}
		
		}
		
		cout << endl;
		
	} else {
		cout << "La invocacion debe tener dos parametros numericos" << endl;
	}
	
	return 0;
}

int randInt(int a, int b){
	return a + rand() % (b-a+1);
}

double randDouble(const double a, const double b){
	return a + ((double)rand()/RAND_MAX)*(b-a);
}
