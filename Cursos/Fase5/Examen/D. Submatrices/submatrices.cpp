// https://omegaup.com/arena/ooi-2021-e3/admin/#problems/submatriz
#include <bits/stdc++.h>

using namespace std;

int matriz[1001][1001] = {0}; // Define una matriz del tamaño maximo e inicializa en 0
int submatriz[1001][1001] = {0}; // Define una matriz del tamaño maximo e inicializa en 0
int resultado[1001][1001] = {0}; // Define una matriz para almacenar el resultado.
int mat_fil; // Cantidad de filas de la matriz
int mat_col; // Cantidad de columnas de la matriz
int sub_fil; // Cantidad de filas de la submatriz
int sub_col; // Cantidad de columnas de la submatriz

// Devuelve verdadero si la region con esquina superior izquierda en x,y
// contiene a la submatriz
bool es_submatriz(int x, int y) {
    // Recorrer la submatriz
    for (int i = 0; i < sub_fil; ++i) {
        for (int j = 0; j < sub_col; ++j) {
            // Sumar i a la fila x para obtener la posicion correcta de la region en la matriz grande.
            // Sumar j a la columna y para obtener la posicion correcta de la region en la matriz grande.
            if (submatriz[i][j] != matriz[x + i][y + j]) {
                return false;
            }
        }
    }
    // Si llegamos a este punto, significa que la region de la matriz is igual a la submatriz
    return true;
}

// Rellena la region de la matriz resultado con 1s.
// Esta region inicia en la esquina superior izquierda (x,y).
void pinta_submatriz(int x, int y) {
    for (int i = 0; i < sub_fil; ++i) {
        for (int j = 0; j < sub_col; ++j) {
            resultado[x + i][y + j] = 1;
        }
    }
}

int main() {
    // Leer el tamaño de la matriz y llenarla
    cin >> mat_fil >> mat_col;
    for (int i = 0; i < mat_fil; ++i) {
        for (int j = 0; j < mat_col; ++j) {
            cin >> matriz[i][j];
        }
    }
    // Leer el tamaño de la submatriz y llenarla
    cin >> sub_fil >> sub_col;
    for (int i = 0; i < sub_fil; ++i) {
        for (int j = 0; j < sub_col; ++j) {
            cin >> submatriz[i][j];
        }
    }

    // Recorrer la matriz grande de izquierda a derecha y de arriba hacia abajo.
    // Nota que solo llegamos hasta la fila mat_fil - sub_fil debido a que esta es la ultima
    // fila en donde podria caber una submatriz. Lo mismo sucede para las columnas.
    for (int i = 0; i <= mat_fil - sub_fil; ++i) {
        for (int j = 0; j <= mat_col - sub_col; ++j) {
            if (es_submatriz(i, j)) {
                pinta_submatriz(i, j);
            }
        }
    }

    // Imprimir la matriz resultado.
    for (int i = 0; i < mat_fil; ++i) {
        for (int j = 0; j < mat_col; ++j) {
            cout << resultado[i][j] << " ";
        }
        cout << "\n";
    }
    

    return 0;
}