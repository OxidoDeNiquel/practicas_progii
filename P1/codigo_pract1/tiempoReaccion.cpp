#include <iostream>
#include <time.h>
#include <cmath>

using namespace std;

int main(int argc, char* argv[]) {
    struct timespec inicio, fin;

    if (argc == 2) {
        int repeticiones = atoi(argv[1]);

        for (int i = 0; i < repeticiones; i++) {
            string linea;
            cout << i + 1 << ") Pulse la tecla de fin de línea (solo Enter), por favor ..." << endl;

            // Inicio de tiempo REAL
            clock_gettime(CLOCK_REALTIME, &inicio);

            getline(cin, linea); // Espera a que pulses Enter

            // Fin de tiempo REAL
            clock_gettime(CLOCK_REALTIME, &fin);

            if (linea.empty()) {
                // Calcular diferencia
                long segs = fin.tv_sec - inicio.tv_sec;
                long nanosegs = fin.tv_nsec - inicio.tv_nsec;
                double total = segs + nanosegs * 1e-9;

                // Redondear a 4 decimales matemáticamente
                int decimales = 4;
                double factor = pow(10, decimales);
                double redondeado = round(total * factor) / factor;

                cout << "✅ Tiempo de reacción: " << redondeado << " segundos" << endl;
            } else {
                cout << "⚠️ Has escrito algo distinto de solo Enter." << endl;
            }
        }
    } else {
        cout << "La invocación debe tener un parámetro numérico" << endl;
    }

    return 0;
}
