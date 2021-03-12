// Toma de Decisiones
// https://omegaup.com/arena/problem/Toma-de-decisiones/

#include <iostream>

using namespace std;

int main() {

    // Lectura
    int numeroA = 0;
    int numeroB = 0;

    cin>>numeroA;
    cin>>numeroB;

    // Procesar

    if ( (numeroA + numeroB) == 5 ) {
        // si se cumple

        // numeroB = numeroB + 3;
        numeroB += 3;

        cout<< (2 * numeroA) + numeroB;

    } else {
        //sino se cumple
        // numeroA = numeroA - 1;
        numeroA -= 1;

        if ((((7 * numeroA) + numeroB) % 2) == 0 ) {
            // si entra es par 7A+B

            cout<<(numeroA - numeroB);

        } else {
            // sino entra es impar 7A+B

            cout<<(numeroA * numeroB);
        }


    }

    return 0;
}