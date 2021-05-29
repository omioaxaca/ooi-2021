// https://omegaup.com/arena/problem/moscas/#problems
#include <bits/stdc++.h>
#define TIEMPO_MAX 60000

using namespace std;

int main() {
    int moscas;
    cin >> moscas;

    // Vectores para representar:
    //  El tiempo en que nacen las moscas
    //  El tiempo en que mueren las moscas
    //  La cantidad de moscas vivas durante el tiempo i
    vector<int> nacimientos(TIEMPO_MAX + 1);
    vector<int> muertes(TIEMPO_MAX + 1);
    vector<int> moscas_vivas_en_tiempo(TIEMPO_MAX + 1);

    // Leer tiempo de inicio de vida y muerte de cada mosca
    for (int mosca = 0; mosca < moscas; ++mosca) {
        int t_n, t_m;
        cin >> t_n >> t_m;
        // Guardar el tiempo de nacimiento y muerte
        nacimientos[t_n]++;
        muertes[t_m]++;
    }

    // Rellenar el arreglo de moscas vivas a traves del tiempo
    int contador = 0;
    for (int i = 1; i <= TIEMPO_MAX; ++i) {
        contador += nacimientos[i]; // El contador incrementa de acuerdo a la cantidad de moscas que nacieron en el tiempo i
        contador -= muertes[i];     // El contador disminuye de acuerdo a la cantidad de moscas que murieron en el tiempo i
        moscas_vivas_en_tiempo[i] = contador; // La cantidad de moscas vivas en el tiempo i equivale al valor del contador
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