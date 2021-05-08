#include <iostream>

using namespace std;

/*
  Ámbito global: el alcance de todo el programa
*/

int suma(int a, int b) {
  // los parámetros de una función
  // solo viven en el ámbito de la función
  int resultado = a + a + b + b;
  return resultado;
}


int main() { // { indica que inicia el ámbito de una función
  suma(5, 7);
  int suma = 0; // variable local
  int valor = 0;
  cout << "Valor en ámbito de main: " << valor << endl; // imprime 0

  if (true) {
    int valor = 10; // valor solo va a existir dentro
    // de las llaves que componen al if
    suma += valor; // 0 + 10
    cout << "Valor en ámbito de if: " << valor << endl; // imprime 10
    valor += 5; // 15
    cout << "Valor en ámbito de if: " << valor << endl; // imprime 15
    suma += valor; // 10 + 15 = 25
  }

  valor += 7;
  cout << "Valor en ámbito de main: " << valor << endl; // imprime 7
  cout << "Valor de suma: " << suma << endl;
} // indica en donde termina el ámbito de una función