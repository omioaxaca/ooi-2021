// Barrancas del cobre
//https://omegaup.com/arena/ooi-2020-ex-2-B/practice/#problems/OMI2015LENGUAJE1
//
// 6 4 -> 6 vistas y se deben visitar 4
// Vistas:      2    1   3   2   6   2
// Diferencia:  0   -1   2  -1   4  -4
//
// Solucion 2:
//  Hacer lo mismo de la solucion 1. Sin embargo, podemos utilizar un precalculo para
//  saber la emocion total que se puede formar en cualquier grupo de k elementos.
//  emocionk = emocion[i+k] - emocion[i];
//  donde emocion[i] representa la emocion total al recorrer las vistas iniciando desde la 0.
//
// Complejidad: O(n)
//
//  Demostracion del precalculo de sumas:
//  sumatoria(i) = suma desde el elemnto 0 hasta i
//  indices        : 0   1   2   3   4   5
//  valores        : 1   6   2   4   3   7
//  sumatoria(i)   : 1   7   9   13  16  23
//  Ejemplo: 
//  sumatoria(3) = 13
//  sumatoria(1) = 7
//  
//  Sumatoria del rango [i, j]
//  sumatoria_i_j = sumatoria(j) - sumatoria(i - 1)
//  sumatoria_2_4 = sumatoria(4) - sumatoria(1) = 16 - 7 = 9
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> valores(n);

    for (int i = 0; i < n; i++) {
        cin >> valores[i];
    }

    // Calcular la diferencia en emocion al ir de la vista i-1 a la vista i.
    vector<int> diferencias(n);
    for (int i = 1; i < n; i++) {
        diferencias[i] = valores[i] - valores[i - 1];
    }

    // Precalcular la sumatoria de la emocion
    vector<int> sumatoria_emocion(n);
    sumatoria_emocion[0] = diferencias[0];
    for (int i = 1; i < n; i++) {
        sumatoria_emocion[i] = sumatoria_emocion[i - 1] + diferencias[i];
    }

    // Iniciar la emocion en un valor muy pequeño.
    int maxima_emocion = INT32_MIN; // Valor mas pequeño que puede representar un entero de 32 bits

    // Simular la visita a cada uno de los grupos de tamanio k posibles.
    for (int i = 0; i < n - k + 1; i++) {
        // Iniciar medida de la emocion
        int emocion = 0;
        // Empezar el grupo en la posicion i y tomar los k elementos siguientes
        // for (int j = i + 1; j < i + k; j++) {
        //     emocion += diferencias[j];
        // }
        emocion = sumatoria_emocion[i + k - 1] - sumatoria_emocion[i];

        // Actualizar el valor de la emocion maxima.
        if (emocion > maxima_emocion) {
            maxima_emocion = emocion;
        }
    }
    cout << maxima_emocion << "\n";



    return 0;
}