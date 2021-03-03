// Dias a segundos
// https://omegaup.com/course/ooi_2021_gb/assignment/ejercicio-clase01/admin/#problems/Dias-a-segundos
#include <iostream>

using namespace std;

int main() {
    int dias; // Declarar la variable dias
    cin >> dias; // Leer un numero entero de la consola y guardarlo en dias.
    int segundos = 0; // Declarar la variable segundos e inicializar en 0.

    // Multiplicar la cantidad de dias por 24*60*60
    // Nota: El operador * se usa para multiplicacion
    segundos = dias * 24 * 60 * 60;

    cout << segundos; // Imprimir el resultado

    return 0;
}