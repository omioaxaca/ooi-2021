// Operadores que existen en C++
// +    Suma
// -    Resta
// *    Multiplicacion
// /    Division (entera cuando las variables son enteras o fracional cuando son float)
// %    Modulo (residuo de una division entera)
#include <iostream>

using namespace std;

int main() {
    // Demostracion de operadores
    int a = 5;
    int b = 2;

    cout << a / b; // 2, porque una division entera no tiene punto decimal.
                   // el valor se trunca a la parte entera.
                   // Si quiero una division con parte decimal, entonces tengo que usar floats.
    cout <<  "\n"; // Imprimir linea en blanco
    cout << a % b; // 1, el residuo de la division entera de 5 / 2.
    

    return 0;
}