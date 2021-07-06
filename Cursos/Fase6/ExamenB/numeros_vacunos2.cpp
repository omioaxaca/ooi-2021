// https://omegaup.com/arena/problem/cnums
// Solucion utilizando __builtin_popcount
#include <bits/stdc++.h>

using namespace std;


int main() {
    int ini;
    int fin;
    cin >> ini >> fin;

    int resultado = 0;
    for (int i = ini; i <= fin; ++i) {
        if (__builtin_popcount(i) <= 4) {
            resultado++;
        }
    }

    cout << resultado << "\n";

    return 0;
}