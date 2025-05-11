#include <iostream>
#include <ctime>
#include <cstdlib>
#include "genNum.hpp"

using namespace std;
// Pre: a ≤ b ∧ b − a ≤ RAND MAX donde a y b son los dos primeros argumentos
// Post: Escribe un entero pseudoaleatorio en el intervalo [a, b]
/*
int main(int argc, char* argv[]) {
	if (argc == 3) {
		/* TEST RANDINT
		srand(time(nullptr));
		int a = atoi(argv[1]);
		int b = atoi(argv[2]);
		
		cout << randInt(a,b) << endl;
		
		
		//TEST RANDDOUBLE
		srand(time(nullptr));
		double a = atof(argv[1]);
		double b = atof(argv[2]);
		cout << randDouble(a,b) << endl;
	} else {
		cout << "La invocacion debe tener dos parametros numericos" << endl;
	}
	
	return 0;
}
*/
int randInt(int a, int b){
	return a + rand() % (b-a+1);
}

double randDouble(const double a, const double b){
	return a + ((double)rand()/RAND_MAX)*(b-a);
}
