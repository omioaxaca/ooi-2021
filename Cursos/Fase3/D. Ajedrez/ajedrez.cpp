// https://omegaup.com/arena/problem/Tablero-de-Ajedrez
#include <bits/stdc++.h>

using namespace std;

int main() {
    char columna_letra;
    int fila;
    cin >> columna_letra >> fila;

    // Convertir la columna en un numero.
    // Recordar que un char guarda el codigo ASCII de una letra.
    // En el caso de la 'a', esta vale 95. Cuando se le resta 'a',
    // en realidad se esta restando 95. Es decir, 'a' - 'a' = 95 - 95 = 0.
    // Dado que el resultado es 0, se suma 1 para que de esta forma, 
    // 'a' sea equivalente a 1, 'b' a 2, 'c' a 3, etc.
    int columna = columna_letra - 'a' + 1;

    // Evaluar la paridad de la columna y fila para determinar
    // el color de la casilla.
    if (columna % 2 == 1 && fila % 2 == 1 ||
        columna % 2 == 0 && fila % 2 == 0) {
        cout << "NEGRO\n";
    }
    else if (columna % 2 == 1 && fila % 2 == 0 ||
             columna % 2 == 0 && fila % 2 == 1)
    {
        cout << "BLANCO\n";
    }

    return 0;
}