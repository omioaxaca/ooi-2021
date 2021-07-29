// https://www.hackerrank.com/challenges/permutation-equation/problem

// @autor Esaú Poralta
// @email esau.opr@gmail.com

#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, num;
    map<int, int> hash;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> num;
        hash[num] = i+1;
    }

    for (int i = 1; i <= n; i++) {
        cout << hash[hash[i]] << "\n";
    }

    return 0;
}
