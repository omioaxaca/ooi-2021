// https://omegaup.com/arena/ooi-2021-e3/admin/#problems/Coeficiente-binomial-recursivo
#include <bits/stdc++.h>

using namespace std;

// Variable para contar la cantidad de llamadas totales.
int llamadas = 0;

int f(int n, int k) {
    // Incrementar la cantidad de llamadas
    llamadas++;
    // Casos base.
    if (n == k || k == 0) {
        return 1;
    }
    // Paso recursivo.
    return f(n - 1, k) + f(n - 1, k - 1);
}

int main() {
    int n;
    int k;
    cin >> n >> k;
    cout << f(n, k) << " " << llamadas;

    return 0;
}
