#include <bits/stdc++.h>

using namespace std;

// Regresa la sumatoria de los numeros en el rango [inicio, fin]
int obtenerSumatoria(int inicio, int fin, const vector<int>& sumas) {
    int sumaFinal = sumas[fin];
    int sumaInicio = inicio > 0 ? sumas[inicio - 1] : 0;
    return sumaFinal - sumaInicio;
}

int main() {
    int n;
    cin >> n;
    vector<int> numeros(n);
    for (int& numero : numeros) {
        cin >> numero;
    }
    int k;
    cin >> k; // Suma objetivo

    vector<int> sumas(n);
    sumas[0] = numeros[0];
    for (int i = 1; i < sumas.size(); ++i) {
        sumas[i] = sumas[i - 1] + numeros[i];
    }
    
    // Barrido
    unordered_set<int> visitados;
    for (int i = 0; i < n; ++i) {
        // k = sumatoria(x, y), donde y es equivalente a la posicion
        // actual.
        // k = sumatoria(x, i)
        // k = sumatoria(0, i) - sumatoria(0, x - 1)
        // Despejamos la variable desconocida
        // sumatoria(0, x - 1) = sumatoria(0, i) - k
        int sumatoriaActual = obtenerSumatoria(0, i, sumas);
        int sumatoriaX = sumatoriaActual - k;
        if (visitados.find(sumatoriaX) != visitados.end()) {
            // Ya se encontro el rango
        }
        visitados.insert(sumatoriaActual);
    }




    int sumaActual = 0;
    for (int i = 0; i < n; ++i) {
        sumaActual += numeros[i];
        // k = sumatoria(x, y), donde y es equivalente a la posicion
        // actual.
        // k = sumatoria(x, i)
        // k = sumatoria(0, i) - sumatoria(0, x - 1)
        // Despejamos la variable desconocida
        // sumatoria(0, x - 1) = sumatoria(0, i) - k
        int sumatoriaX = sumaActual - k;
        if (visitados.find(sumatoriaX) != visitados.end()) {
            // Ya se encontro el rango
        }
        visitados.insert(sumaActual);
    }
    

}