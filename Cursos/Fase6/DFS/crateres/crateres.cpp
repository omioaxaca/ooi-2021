#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int>> Matriz;

// Implementar una DFS para contar la cantidad de rocas en las casillas adyacentes
// a (x,y).
int contarRocas(int x, int y, Matriz& matriz) {
    // Verificar que estemos dentro de la matriz.
    if (x < 0 || x >= matriz.size() || y < 0 || y >= matriz[x].size()) {
        return 0;
    }
    // Revisar si es un estado invalido.
    if (matriz[x][y] == 0) {
        return 0;
    }
    // Marcar la posicion actual como visitada
    int rocas = matriz[x][y];
    matriz[x][y] = 0;
    // Probar con los vecinos adyacentes
    vector<int> coordX = {-1, 0, 1, 0};
    vector<int> coordY = { 0, 1, 0,-1};
    for (int i = 0; i < 4; ++i) {
        int x_i = x + coordX[i];
        int y_i = y + coordY[i];
        rocas += contarRocas(x_i, y_i, matriz);
    }
    return rocas;
}

int main() {
    int filas;
    int columnas;
    cin >> filas >> columnas;

    Matriz superficie(filas, vector<int>(columnas, 0));

    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            cin >> superficie[i][j];
        }
    }

    int craterMayor = 0;
    int maxRocas = 0;
    int numCrateres = 0;
    for (int c = 0; c < columnas; ++c) {
        for (int f = 0; f < filas; ++f) {
            if (superficie[f][c] != 0) {
                // Encontramos un crater
                numCrateres++;
                int numRocas = contarRocas(f, c, superficie);
                if (numRocas > maxRocas) {
                    maxRocas = numRocas;
                    craterMayor = numCrateres;
                }
            }
        }
    }
    
    cout << craterMayor << " " << maxRocas;



    return 0;
}