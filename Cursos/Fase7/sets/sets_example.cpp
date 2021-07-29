#include <bits/stdc++.h>

// #include <iostream>
// #include <set>
// #include <vector>

using namespace std;

int main() {
    // Inicializar los sets
    set<int> set1; // Un set vacio
    set<int> set2 = {1, 2, 3, 4, 5};
    set<int> set3 = {6,5,4,3,2,1};
    vector<int> vec = {0,1,2,3,4,5};
    set<int> set4(vec.begin(), vec.end());

    // Recorrer un set
    for (auto elm:set4) {
        cout << elm << " ";
    }
    cout << "\n";

    for (set<int>::iterator it = set4.begin(); it != set4.end(); it++) {
        cout << *it << " ";
    }
    cout << "\n";

    // Insertar elementos
    set4.insert(1);
    set4.insert(3);
    set4.insert(6);
    set4.insert({7,8,9});
    vector<int> vec2 = {10,11,12};
    set4.insert(vec2.begin(), vec2.end());

    for (auto elm:set4) {
        cout << elm << " ";
    }
    cout << "\n";

    // Borrar elementos
    set4.erase(3);

    set4.erase(set4.find(10), set4.end());
    set4.erase(set4.find(1), set4.find(5));

    for (auto elm:set4) {
        cout << elm << " ";
    }
    cout << "\n";

    // Limpiar todo
    set4.clear();
    for (auto elm:set4) {
        cout << elm << " ";
    }
    cout << "\n";

    return 0;
}
