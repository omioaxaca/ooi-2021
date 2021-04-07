#include <bits/stdc++.h>

using namespace std;

int main() {
    int n_nums;
    int mayor;
    int num;

    cin >> n_nums;
    cin >> mayor;

    n_nums --;
    while(n_nums > 0) {
        n_nums --;

        cin >> num;
        if (num > mayor) {
            mayor = num;
        }
    }

    cout << mayor << endl;

    return 0;
}
