// Encontrar si existe una pareja de numeros que al sumarlos se obtiene k.
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

    bool existenNumeros = false;
    unordered_set<int> visitados;
    for (int i = 0; i < n; ++i) {
        int requerido = sumaObjetivo - numeros[i];
        // Revisar si ya lo visitamos antes
        if (visitados.find(requerido) != visitados.end()){
            existenNumeros = true;
            break;
        }
        // Agregar el elemento actual al set de visitados
        visitados.insert(numeros[i]);
    }
    if (existenNumeros) {
        cout << "Si";
    }
    else {
        cout << "No";
    }
    
    return 0;
}