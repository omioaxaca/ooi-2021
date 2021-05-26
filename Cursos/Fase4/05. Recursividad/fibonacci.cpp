#include <bits/stdc++.h>

using namespace std;

int fibonacci(int n, vector<int> &estados) {
    if (n == 0 || n == 1) {
        return n;
    }

    if (estados[n] != -1) {
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
    vector<int> estados(n, -1);

    cout << fibonacci(5, estados) << endl;

    return 0;
}
