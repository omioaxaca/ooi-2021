//https://omegaup.com/course/ooi_2021_fase_456/assignment/ejercicios-3/#problems/Matrices-concentricas
#include <bits/stdc++.h>

using namespace std;

// Declarar una matriz estatica del tamanio maximo de n (350)
int matriz[353][353];
int n;

// Regresa verdadero si la fila contiene solo elementos iguales al valor esperado
bool verificar_fila(int valorEsperado, int fila, int colInicial, int colFinal) {
    bool esValido = true; // Asumir que la fila es valida
    for (int c = colInicial; c <= colFinal; ++c) {
        // Si al menos un valor es diferente del esperado, la fila ya no es valida
        if (matriz[fila][c] != valorEsperado) {
            esValido = false;
        }
    }
    return esValido;
}

bool verificar_columna(int valorEsperado, int columna, int filaInicial, int filaFinal) {
    bool esValido = true;
    for (int f = filaInicial; f <= filaFinal; ++f) {
        if (matriz[f][columna] != valorEsperado) {
            esValido = false;
        }
    }
    return esValido;
}

int main() {
    // Leer n
    cin >> n;
    // LLenar la matriz de datos
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matriz[i][j];
        }
    }

    bool esConcentrica = true; // Asumir que la matriz es concentrica
    
    // Verificar que las filas exteriores de cada "submatriz" interna sean correctas.
    int valorEsperado = 0;
    for (int fila = 0; fila <= n/2; ++fila) {
        int diff = fila; // Representa la diferencia de celdas donde inicia la "submatriz" interna
        // Verificar la fila superior
        if (!verificar_fila(valorEsperado, fila, diff, (n - 1) - diff)) {
            esConcentrica = false;
        }
        // Verificar la fila inferior
        if (!verificar_fila(valorEsperado, (n - 1) - diff, diff, (n - 1) - diff)) {
            esConcentrica = false;
        }
        valorEsperado++; 
    }

    // Verificar que las columnas exteriores de cada "submatriz" interna sean correctas.
    valorEsperado = 0;
    for (int columna = 0; columna <= n/2; ++columna) {
        int diff = columna; // Representa la diferencia de celdas donde inicia la "submatriz" interna
        // Verificar la columna superior
        if (!verificar_columna(valorEsperado, columna, diff, (n - 1) - diff)) {
            esConcentrica = false;
        }
        // Verificar la columna inferior
        if (!verificar_columna(valorEsperado, (n - 1) - diff, diff, (n - 1) - diff)) {
            esConcentrica = false;
        }
        valorEsperado++;
    }

    // Imprimir el resultado
    if (esConcentrica) {
        cout << "1";
    }
    else {
        cout << "0";
    }

    return 0;
}