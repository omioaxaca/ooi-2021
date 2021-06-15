// https://omegaup.com/arena/problem/Proyectiles#problems
// Solucion: Buscar cada uno de los proyectiles dentro de la lista.
// Usar busqueda binaria para hacer eficiente el algoritmo y evitar errores de tiempo.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Crear un vector de vectores.
// El vector interior se usa para almacenar dos valores, los valores de x y y.
vector<vector<int>> proyectiles;
// Definir constantes para representar la coordenadas X y Y dentro del vector
const int X = 0;
const int Y = 1;


bool busqBin(vector<int> proyectil) {
    int ini = 0;
    int fin = proyectiles.size() - 1;
    while (ini <= fin) {
        int mit = ini + (fin - ini) / 2;
        if (proyectiles[mit][X] == proyectil[X]) {
            if (proyectiles[mit][Y] == proyectil[Y]) {
                return true;
            }
            else if(proyectiles[mit][Y] > proyectil[Y]) {
                fin = mit - 1; 
            }
            else {
                ini = mit + 1;
            }
        }
        else if(proyectiles[mit][X] > proyectil[X]) {
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
    vector<int> proyectil(2);
    for (int i = 0; i < n; i++) {
        cin >> proyectil[X] >> proyectil[Y];
        // Insertar el proyectil en el vector de proyectiles
        proyectiles.push_back(proyectil);
    }

    // Ordenar el vector, por defecto esto toma el orden lexicografico de cada vector interno
    // Es decir, si te tiene un vector asi:
    // {
    //     {1, 3},
    //     {5, 8},
    //     {1, 2},
    //     {3, 9}
    // }
    // Al ser ordenado quedara:
    // {
    //     {1, 2},
    //     {1, 3},
    //     {3, 9},
    //     {5, 8}
    // }
    sort(proyectiles.begin(), proyectiles.end());
    
    // Leer cada proyectil y buscar si ya existe en nuestro vector
    for (int i = 0; i < k; i++) {
        cin >> proyectil[X] >> proyectil[Y];
        if (busqBin(proyectil) == true) {
            cout << "0\n";
        }
        else {
            cout << "1\n";
        }
    }


    return 0;
}