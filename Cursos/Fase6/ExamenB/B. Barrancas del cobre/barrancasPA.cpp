// Barrancas del cobre
//https://omegaup.com/arena/ooi-2020-ex-2-B/practice/#problems/OMI2015LENGUAJE1
//
// 6 4 -> 6 vistas y se deben visitar 4
// Vistas:      2    1   3   2   6   2
// Diferencia:  0   -1   2  -1   4  -4
// Solucion 1:
//  Recorrer el arreglo de vistas y probar con todas las grupos contiguos de tamaño k.
//  Para cada uno de esos grupos calcular el total de la emocion y guardar el mayor.
//  Complejidad:
//      O(n*k) = O(50,000*50,000) = O(2,500,000,000)
//  Memoria:
//      Valor mas grande de la emocion es 10,000*25,000
//      Valor mas pequenio de la emocion es -10,000*25,000

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

    vector<int> diferencias(n);
    for (int i = 1; i < n; i++) {
        diferencias[i] = valores[i] - valores[i - 1];
    }

    // Iniciar la emocion en un valor muy pequeño.
    int maxima_emocion = INT32_MIN; // Valor mas pequeño que puede representar un entero de 32 bits

    // Simular la visita a cada uno de los grupos de tamanio k posibles.
    for (int i = 0; i < n - k; i++) {
        // Iniciar medida de la emocion
        int emocion = 0;
        // Empezar el grupo en la posicion i y tomar los k elementos siguientes
        for (int j = i + 1; j < i + k; j++) {
            emocion += diferencias[j];
        }
        // Actualizar el valor de la emocion maxima.
        if (emocion > maxima_emocion) {
            maxima_emocion = emocion;
        }
    }
    cout << maxima_emocion << "\n";



    return 0;
}