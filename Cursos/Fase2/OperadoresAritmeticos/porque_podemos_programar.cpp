// Operadores aritmeticos
// Problema de omegaup: https://omegaup.com/course/ooi_2021_gb/assignment/ejercicio-clase01/admin/#problems/Porque-podemos-programar

// Operadores que existen en C++
// +    Suma
// -    Resta
// *    Multiplicacion
// /    Division (entera cuando las variables son enteras o fracional cuando son float)
// %    Modulo (residuo de una division entera)
#include <iostream>

using namespace std;

int main() {
    // Declarar variables
    // Usar float porque son reales (numeros con punto decimal)
    float x = 0;
    float y = 0;
    float z = 0;

    cin >> x; // Leer el valor de x

    // Calcular y
    z = (x + x * x) / (5 * x + 3);
    y = (z + x) * (z / (z + 2 * x));
    
    cout << y; // Imprimir el valor de y
    

    return 0;
}