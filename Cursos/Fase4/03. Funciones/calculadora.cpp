#include <iostream>
#include <string>

using namespace std;

/*
  Escribir un programa que reciba como entrada
  1. caracter (+, -, /, *)
  2. Dos enteros

  Salida:
   Un texto que diga:
   El resultado de la operación <<operación>> es: <<resultado>>

  NOTA: Utilizar funciones para cada operación
*/

int suma(int a, int b) {
  return a + b;
}

int resta(int a, int b) {
  return a - b;
}

float division(int a, int b) { // poner los parametros como float
  return (float) a / b; // NOTA: Si les interesa revisar el tema: parseo de datos 
}

int multiplicacion(int a, int b) {
  return a * b;
}

void imprimirResultado(char operacion, float resultado) {
  cout << "El resultado de la operación ";
  switch(operacion) {
    case '+':
      cout << "suma es: " << resultado;
    break;
    case '-':
      cout << "resta es: " << resultado;
    break;
    case '/':
      cout << "division es: " << resultado;
    break;
    case '*':
      cout << "multiplicacion es: " << resultado;
    break;
  }
}

void imprimirResultadoEnPantalla(string operacion, float resultado) {
  cout << "El resultado de la operación " << operacion << " es: " << resultado;
  //printf("El resultado de la operación %s es: %.2f", operacion.c_str(), resultado); // podemos cambiar la manera en que se imprime en pantall modificando solo la función sin tener que mover todo nuestro código
}

int main() {
  char operacion;
  int numero1, numero2;
  float resultado;

  cin >> operacion;
  cin >> numero1 >> numero2;

  switch(operacion) {
    case '+':
      //imprimirResultado(operacion, suma(numero1, numero2));
      imprimirResultadoEnPantalla("suma", suma(numero1, numero2));
      break;
    case '-':
      //imprimirResultado(operacion, resta(numero1, numero2));
      imprimirResultadoEnPantalla("resta", resta(numero1, numero2));
      break;
    case '/':
      //imprimirResultado(operacion, division(numero1, numero2));
      imprimirResultadoEnPantalla("division", division(numero1, numero2));
      break;
    case '*':
      //imprimirResultado(operacion, multiplicacion(numero1, numero2));
      imprimirResultadoEnPantalla("multiplicacion", multiplicacion(numero1, numero2));
      break;
  }
}