// Contar la cantidad de parejas de numeros que al sumarlos se obtiene k.
// Nota, se consideran disntintos si i != j
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> numeros(n);
    for (int i = 0; i < n; ++i) {
        cin >> numeros[i];
    }

    int sumaObjetivo;
    cin >> sumaObjetivo;

    int contadorParejas = 0;
    unordered_map<int, int> visitados;
    for (int i = 0; i < n; ++i) {
        int requerido = sumaObjetivo - numeros[i];
        // Agregar la cantidad de veces que hemos visitado el elemento requerido.
        contadorParejas += visitados[requerido]; // Si el valor no ha sido visitado, se crea la llave con un valor por defecto de 0.

        // Agregar el elemento actual a la cuenta de visitados
        visitados[numeros[i]]++;
    }

    cout << contadorParejas << "\n";
    
    return 0;
}