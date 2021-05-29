#include <bits/stdc++.h>

using namespace std;


int sum_dig(int n) {
    if (n < 10) {
        return n;
    }

    return n % 10 + sum_dig(n / 10);
}


int main () {
    cout << sum_dig(91231) << endl;
    return 0;
}
