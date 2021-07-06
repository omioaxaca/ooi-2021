// https://omegaup.com/arena/problem/cnums
// Solucion parcial utilizando simulacion. No entra en tiempo.
#include <bits/stdc++.h>

using namespace std;

int cuenta_unos(int n) {
    int contador = 0;
    while (n > 0) {
        if (n % 2 == 1) {
            contador++;
        }
        n /= 2;
        if (contador > 4)
            break;
    }
    return contador;
}

int main() {
    int ini;
    int fin;
    cin >> ini >> fin;

    int resultado = 0;
    for (int i = ini; i <= fin; ++i) {
        if (cuenta_unos(i) <= 4) {
            resultado++;
        }
    }

    cout << resultado << "\n";

    return 0;
}