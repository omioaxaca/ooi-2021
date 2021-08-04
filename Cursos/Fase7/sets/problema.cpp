// Tenemos matrices de nxm
// => 3x5
// 0  1  2  3  4
// 5  6  7  8  9
// 10 11 12 13 14

// Explotar estas celdas
// (1,1)
// (2,2)
// (1,2)

// Queremos saber que celdas no fueron explotadas

#include <bits/stdc++.h>

using namespace std;

int main() {
    // (fila, columna) => (fila-1)*m + columna-1
    int m, n;
    int casos;
    cin >> n >> m;

    set<int> myset;

    for (int i = 0; i < n*m; i++) {
        myset.insert(i);
    }

    cin >> casos;

    while(casos--) {
        int i,j;
        cin >> i >> j;
        myset.erase((i-1)*m + j-1);
    }

    for (auto elm :myset) {
        int fila = elm / m;
        int col = elm%m;
        cout << fila+1 << " " << col+1 << endl;
    }

    return 0;
}
