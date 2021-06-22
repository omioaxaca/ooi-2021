/*
  https://omegaup.com/arena/problem/COMI-Parentesis#problems
  Solución: Pilas o un contador.

  Necesitamos iterar la cadena e ir guardando los parentesis que veamos que
  abren para despues ver que hacer con ellos cuando encontremos uno cuando 
  cierra, y cancelarlos:

  Cada que vemos un parentesis que abre lo agregamos a la pila.
  Cada que vemos un parentesis que cierra:
    Tenemos que verificar si tenemos un partensis en nuestra pila que abre para que se puedan cancelar.
    Si no tenemos un parentesis para cancelar quiere decir que la expresion esta mal
    Si si tenemos, solo borramos ese parentesis de la pila.
  Al terminar de procesar toda la cadena tenemos que verificar si tenemos 
  todavia elementos en la pila sin procesar si es asi quiere decir que la expresion no es valida.
  En caso contrario la pila esta vacia y es una expresion valida.

*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool esValida (string s) {
  stack<char> pila;

  for (int i=0; i<s.size(); i++) {
    char actual = s[i];

    if (actual == '(') {
      pila.push(actual);
    } else {
      if (pila.empty()) {
        return false;
      } else {
        pila.pop();
      }
    }
  }

  if (pila.empty()) {
    return true;
  }

  return false;
}

int main() {

  string expresion;
  cin>>expresion;

  if (esValida(expresion)){
    cout<<"SI"<<endl;
  } else {
    cout<<"NO"<<endl;
  }

  return 0;
}