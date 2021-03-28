// Filtrando Multiplos
// https://omegaup.com/arena/problem/Filtrando-multiplos/
// Nota: Esta elaborado sin usar arreglos, despues regresaremos cuando veamos el tema.

#include<iostream>

using namespace std;

int main() {

    // LECTURA DE DATOS:
    int totalDeNumeros = 0;
    int k = 0;
    
    cin>>totalDeNumeros;
    cin>>k;

    for (int i=1; i<=totalDeNumeros; i++) {
        // i = 1,2,3,4,5     totalDeNumeros = 5

        int numeroActual = 0;
        cin>>numeroActual;

        if (numeroActual % k == 0) {
            cout<<numeroActual;
        } else {
            cout<<"X";
        }

        if (i < totalDeNumeros) {
            cout<<" ";
        }
    }

    return 0;
}
