#include <bits/stdc++.h>

using namespace std;

int main (){
    int LD;
    cin >> LD;

    if (LD == 61) {
        cout << "Brasilia" << endl;
    } else if (LD == 71) {
        cout << "Salvador" << endl;
    } else if (LD == 11) {
        cout << "Sao Paulo" << endl;
    } else if (LD == 21) {
        cout << "Rio de Janeiro" << endl;
    } else if (LD == 32) {
        cout << "Juiz de Fora" << endl;
    } else if(LD == 19) {
        cout << "Campinas" << endl;
    } else if (LD == 27) {
        cout << "Vitoria" << endl;
    } else if (LD == 31) {
        cout << "Belo Horizonte" << endl;
    } else {
        cout << "LD no encontrada" << endl;
    }
    return 0;
}
