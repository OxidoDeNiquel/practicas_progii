#include <iostream>
#include <time.h>
#include <sys/resource.h> // Para getrusage

using namespace std;

int main () {
    struct timespec inicioReal, finReal;
    struct timespec inicioCPU, finCPU;
    struct rusage uso;

    // Tiempo real (reloj de pared)
    clock_gettime(CLOCK_REALTIME, &inicioReal);
    // Tiempo de CPU total
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &inicioCPU);

    // Código a medir
    int numero;
    cout << "Escribe un numero entero: ";
    cin >> numero;
    cout << "El doble es: " << numero * 2 << endl;

    // Fin de los tiempos
    clock_gettime(CLOCK_REALTIME, &finReal);
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &finCPU);
    getrusage(RUSAGE_SELF, &uso); // Uso de CPU dividido en user y sys

    // Calcular tiempo real
    long segsReal = finReal.tv_sec - inicioReal.tv_sec;
    long nanosegsReal = finReal.tv_nsec - inicioReal.tv_nsec;
    double totalReal = segsReal + nanosegsReal * 1e-9;

    // Calcular tiempo de CPU total
    long segsCPU = finCPU.tv_sec - inicioCPU.tv_sec;
    long nanosegsCPU = finCPU.tv_nsec - inicioCPU.tv_nsec;
    double totalCPU = segsCPU + nanosegsCPU * 1e-9;

    // Tiempos de usuario y sistema (getrusage)
    double tiempoUsuario = uso.ru_utime.tv_sec + uso.ru_utime.tv_usec * 1e-6;
    double tiempoSistema = uso.ru_stime.tv_sec + uso.ru_stime.tv_usec * 1e-6;

    // Mostrar resultados
    cout << "⏱️ Tiempo real:         " << totalReal << " segundos" << endl;
    cout << "🧠 Tiempo CPU total:    " << totalCPU << " segundos" << endl;
    cout << "👨‍💻 Tiempo en usuario:   " << tiempoUsuario << " segundos" << endl;
    cout << "🛠️ Tiempo en sistema:    " << tiempoSistema << " segundos" << endl;

    return 0;
}
