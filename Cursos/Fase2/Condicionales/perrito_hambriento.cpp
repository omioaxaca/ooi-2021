// El perrito que quiere un hueso
// https://omegaup.com/course/ooi_2021_ga/assignment/E01/admin/#problems/El-perrito-que-quiere-un-hueso 
#include <bits/stdc++.h>

using namespace std;

int main() {
    int olor_1;
    int tam_1;
    int olor_2;
    int tam_2;
    // Leer el olor y tamnio de los huesos.
    cin >> olor_1 >> tam_1;
    cin >> olor_2 >> tam_2;
    // SI olor_1 mayor que olor_2 Y tam_1 mayor que tam_2
    //    Imprimir Hueso 1
    // DE LO CONTRARIO SI olor_2 mayor olor_1 Y tam_2 mayor que tam_2
    //    Imprimir Hueso 2
    // DE LO CONTRARIO
    //    Imprimir Perrito confundido :(
    // &&   --> Y   (Expresion logica AND)
    // ||   --> O   (Expresion logica OR)
    // !    --> NO  (Expresion logica NOT)
    if (olor_1 > olor_2 && tam_1 > tam_2) {
        cout << "Hueso 1";
    }
    else if(olor_2 > olor_1 && tam_2 > tam_1) {
        cout << "Hueso 2";
    }
    else {
        cout << "Perrito confundido :(";
    }

    return 0;
}