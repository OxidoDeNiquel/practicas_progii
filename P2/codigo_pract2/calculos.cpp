#include <iostream>
#include <ctime>
#include <cstdlib>
#include "calculos.hpp"

using namespace std;

int numCifras(const int n, const int b){
	if( n == 0 ){
		return 1;
	}else{
		if(n < b){
			return 1;
		}else{
			return 1 + numCifras( n/b, b);
		}		
	}
}

int cifra(const int n, const int i, const int b){
	if( i == 1 ){
		return n % b;
	}else{
		return cifra(n/b, i-1, b);
	}
}

int cifraMayor(const int n, const int b){
	if( n < b){
		return n;
	}else{
		int i = n % b;
		
		int j = cifraMayor(n/b, b);
		
		return (i > j) ? i : j;
	}
}

int cifraMasSignificativa(const int n, const int b){
	if(n < b){
		return n;
	}else{
		return cifraMasSignificativa(n/b, b);
	}	
}

int sumaCifras(const int n, const int b){
	if (n == 0) {
		return 0;
	} else {
		return (n % b) + sumaCifras(n / b, b);
	}
}
