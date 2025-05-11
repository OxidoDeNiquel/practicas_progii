#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <time.h>

using namespace std;

int main(int argc, char* argv[]) {
    struct timespec inicioCPU, finCPU;
    
	if (argc == 4) {
		
		int minN = atoi(argv[1]);
		int paso = atoi(argv[2]);
		int nIter = atoi(argv[3]);
		
		for(int i = 0; i < nIter ; i++){
			int n = minN + i * paso;
			int puntosDentro = 0;

			// Tiempo de CPU total
    		clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &inicioCPU);

			for (int j = 0; j < n; ++j) {
				double x = (double)rand() / RAND_MAX;
				double y = (double)rand() / RAND_MAX;

				if (x * x + y * y <= 1.0) {
					puntosDentro++;
				}
			}
			
    		clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &finCPU);

			double piEstimada = 4.0 * puntosDentro / n;
			double errorRelativo = fabs((piEstimada - M_PI) / M_PI) * 100;
			// Calcular tiempo de CPU total
			long segsCPU = finCPU.tv_sec - inicioCPU.tv_sec;
			long nanosegsCPU = finCPU.tv_nsec - inicioCPU.tv_nsec;
			double tiempoCPU = segsCPU + nanosegsCPU * 1e-9;

			cout << "n = " << n << "; PI (estimada) = " << piEstimada << ";\t";
			cout << "Error relativo (%) = " << errorRelativo << ";\t";
			cout << "Tiempo CPU (s) = " << tiempoCPU << endl;
		}
		
	}else{
		cout << "La invocación debe tener tres parámetros: minN paso nIter" << endl;
	}
		
	return 0;
}
