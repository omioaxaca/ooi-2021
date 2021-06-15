// https://omegaup.com/arena/problem/Proyectiles#problems
// Solucion: Buscar cada uno de los proyectiles dentro de la lista.
// Usar busqueda binaria para hacer eficiente el algoritmo y evitar errores de tiempo.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<long long int>> proyectiles;


bool busqBin(vector<int> nuevo) {
    int ini = 0;
    int fin = proyectiles.size() - 1;
    while (ini <= fin) {
        int mit = ini + (fin - ini) / 2;
        if (proyectiles[mit][0] == nuevo[0]) {
            if (proyectiles[mit][1] == nuevo[1]) {
                return true;
            }
            else if(proyectiles[mit][1] > nuevo[1]) {
                fin = mit - 1; 
            }
            else {
                ini = mit + 1;
            }
        }
        else if(proyectiles[mit][0] > nuevo[0]) {
            fin = mit - 1;
        }
        else {
            ini = mit + 1;
        }
    }
    return false;
}

int main() {
    int n;
    int k;
    cin >> n >> k;

    // Crear un vector de 2 posiciones para representar al proyectil
    // Indice 0: Representa x
    // Indice 1: Representa y
    vector<long long int> proyectil(2);
    for (int i = 0; i < n; i++) {
        cin >> proyectil[0] >> proyectil[1];
        // Insertar el proyectil en el vector de proyectiles
        proyectiles.push_back(proyectil);
    }

    // Ordenar primero por x y luego por y
    sort(proyectiles.begin(), proyectiles.end());
    
    for (int i = 0; i < k; i++) {
        vector<int> nuevo(2);
        cin >> nuevo[0] >> nuevo[1];
        if (busqBin(nuevo) == true) {
            cout << "0\n";
        }
        else {
            cout << "1\n";
        }
    }


    return 0;
}