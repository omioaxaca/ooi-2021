// Todos numeros entre ellos
// https://omegaup.com/arena/problem/todosNumerosEntreEllos/
//

#include<iostream>

using namespace std;

int main() {

    int X1;
    int X2;

    // LECTURA DE DATOS
    cin>>X1;
    cin>>X2;

    // PROCESAMIENTO: 
    // DETECTAR ERRORES.

    if (X1 < 0 || X2 < 0 || X1 >= X2) {
        cout<<"Error";
    } else {
        // es valida la entrada y hay que responder el problema:
        /*
            X1=1   X2=8
            1,2,3,4,5,6,7
        */
        for (int i=X1+1; i<X2; i+=2) { // ciclo empezando en el segundo numero de la serie hasta uno antes de X2.
            cout<<i;
            if (i<X2-2) {
                cout<<" "; // imprimir espacio solo entre numeros.
            }
        }
    }

    return 0;
}