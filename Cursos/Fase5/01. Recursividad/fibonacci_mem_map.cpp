#include <bits/stdc++.h>

using namespace std;

int fibonacci(int n, map<int, int> &estados) {
    if (n == 0 || n == 1) {
        return n;
    }

    if (estados.find(n) != estados.end()) {
        return estados[n];
    }

    int parte1 = fibonacci(n-1, estados);
    int parte2 = fibonacci(n-2, estados);

    estados[n] = parte1 + parte2;

    return estados[n];
    // return fibonacci(n-1) + fibonacci(n-2);
}

int main () {
    int n = 5;

    map<int, int> estados;

    cout << fibonacci(8, estados) << endl;

    return 0;
}
