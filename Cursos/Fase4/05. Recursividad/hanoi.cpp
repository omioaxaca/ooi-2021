#include <bits/stdc++.h>

using namespace std;

void hanoi(int n, int A, int B, int C) {
    if (n == 0) {
        return;
    }

    hanoi(n-1, A, C, B);
    cout << A << " " << C << "\n";
    hanoi(n-1, B, A, C);
}

int main () {
    int n = 3;

    hanoi(n, 1, 2, 3);

    return 0;
}
