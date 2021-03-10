// Etapas de la vida
// https://omegaup.com/arena/problem/Etapas-de-la-vida/#problems

#include<iostream>

using namespace std;

int main() {
    int edad = 0;
    
    // Lectura de datos
    cin>>edad;

    if (edad <= 3) {
        cout<<"BEBE";
    }

    if (edad >= 4 && edad < 15) {
        cout<<"NINO";
    }

    if (edad >= 15 && edad < 19) {
        cout<<"JOVEN";
    }

    if (edad >= 19 && edad < 66) {
        cout<<"ADULTO";
    }

    if (edad >= 65) {
        cout<<"ADULTO 3RA";
    }

    return 0;
}