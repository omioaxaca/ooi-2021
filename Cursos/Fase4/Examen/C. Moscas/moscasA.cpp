// https://omegaup.com/arena/problem/moscas/#problems
#include <bits/stdc++.h>
#define TIEMPO_MAX 60000

using namespace std;

int main() {
    int moscas;
    cin >> moscas;

    // Vector para guardar la cantidad de moscas vivas durante el tiempo.
    // El indice i representa la cantidad de moscas vivas en el tiempo i
    vector<int> moscas_vivas_en_tiempo(TIEMPO_MAX + 1, 0); // El problema dice que el tiempo maximo es de 0 hasta 60,000

    // Leer tiempo de inicio de vida y muerte de cada mosca
    for (int mosca = 0; mosca < moscas; ++mosca) {
        int t_n, t_m;
        cin >> t_n >> t_m;
        // Para esta mosca, marcar su tiempo de vida en el arreglo
        for (int i = t_n; i < t_m; ++i) {
            moscas_vivas_en_tiempo[i]++; // Incrementar la cantidad de moscas vivas en el tiempo i
        }
    }

    // Buscar el valor maximo de moscas vivas a traves del tiempo
    int maximo = 0;
    for (int i = 1; i <= TIEMPO_MAX; ++i) {
        if (moscas_vivas_en_tiempo[i] > maximo) {
            maximo = moscas_vivas_en_tiempo[i];
        }
    }
    // Imprimir el maximo
    cout << maximo << "\n";

    // Imprimir todos los rangos donde se encontró la población máxima de moscas
    for (int i = 1; i <= TIEMPO_MAX; ++i) {
        int inicio_rango;
        int fin_rango;
        if (moscas_vivas_en_tiempo[i] == maximo) {
            inicio_rango = i; // Aqui inicia el rango
            // Incrementar el valor de i mientras sea igual al maximo
            while (i <= TIEMPO_MAX && moscas_vivas_en_tiempo[i] == maximo) {
                i++;
            }
            // Ahora i tiene el valor del final del rango
            fin_rango = i;
            cout << inicio_rango << " " << fin_rango << "\n";
        }
    }

    return 0;
}