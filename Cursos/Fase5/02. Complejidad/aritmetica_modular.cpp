#include <bits/stdc++.h>

using namespace std;

int main() {
    int a;
    long long int n;
    int m;

    cin >> a >> n >> m;

    long long int resultado = 1;
    for (long long int i = 1; i <= n; ++i) {
        resultado = (resultado % m) * (a % m);
        resultado = resultado % m;
    }
    cout << resultado;

    return 0;
}