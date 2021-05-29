// https://omegaup.com/arena/problem/AcomodandoOMI/
#include<bits/stdc++.h>

using namespace std;

int main(){
    // Optimizar el uso de CIN
    ios::sync_with_stdio(false); cin.tie(0);
    
    int numeros;
    int a;
    int pos = 0; // Posicion esperada
    cin >> numeros >> a;
    for(int i = 1; i < numeros; i++){
        int n;
        cin >> n;
        // Si el numero actual es menor que a, incrementar la posicion esperada
        if(n < a) {
            pos++;
        }
    }
    cout << pos++ << "\n";
    return 0;
}