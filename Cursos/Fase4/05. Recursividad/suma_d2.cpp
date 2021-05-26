#include <bits/stdc++.h>

using namespace std;


int sum_dig(int n) {
    if (n < 10) {
        return n;
    }

    return n % 10 + sum_dig(n / 10);
}


int f(int x) {
    if (x < 10) {
        return x;
    }

    return f(sum_dig(x));
}


int main () {
    cout << f(987654) << endl;
    return 0;
}
