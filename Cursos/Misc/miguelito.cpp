#include <bits/stdc++.h>

using namespace std;

typedef long long int i64;

int llamadas = 0;

i64 exp(i64 a, i64 n) {
    llamadas++;
    if (n == 0)
        return 1;
    if (n == 1)
        return a;
    if (n % 2 == 0) {
        i64 resultado = exp(a, n /2);
        return resultado * resultado;
    }
    else {
        return exp(a, n - 1) * a;
    }
}

i64 exp_mod(i64 a, i64 n, int mod) {
    if (n == 0)
        return 1;
    if (n == 1)
        return a % mod;
    if (n % 2 == 0) {
        i64 resultado = exp(a, n /2);
        return ((resultado % mod) * (resultado % mod)) % mod;
    }
    else {
        return ((exp(a, n - 1) % mod) * (a % mod)) % mod;
    }
}

int main() {
    i64 a, n, mod;
    cin >> a >> n >> mod;
    cout << exp_mod(a, n, mod) << "\n";

    return 0;
}