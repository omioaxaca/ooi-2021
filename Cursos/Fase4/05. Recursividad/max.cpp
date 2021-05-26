#include <bits/stdc++.h>

using namespace std;

int maximo(vector<int> &numbers, int pos=0) {
    if (pos == numbers.size()-2) {
        return max(numbers[pos], numbers[pos+1]);
    }

    return max(numbers[pos], maximo(numbers, pos+1));
}

int main () {

    vector<int> numbers;

    numbers.push_back(3);
    numbers.push_back(8);
    numbers.push_back(15);
    numbers.push_back(100);
    numbers.push_back(6);
    numbers.push_back(10);

    cout << maximo(numbers) << endl;

    return 0;
}
