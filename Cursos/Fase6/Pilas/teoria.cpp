#include <iostream>
#include <stack>

using namespace std;

/*
  Estructura de datos para almacenar información con el metodo LIFO 
  (Last In First Out) (Ultimo en entrar - Primero en salir)


  Funciones de stack:
  push()   =  Añade un elemento al final de la pila (hasta arriba en la pila)
  top()    =  Recupera el ultimo elemento (el elemento de hasta arriba de la pila)
  pop()    =  Elimina el ultimo elemento (el elemento de hasta arriba de la pila)
  empty()  =  Regresa un TRUE si la pila esta vacia y un FALSE si tiene elementos.
  size()   =  Regresa un Entero con el numero de elementos dentro de la pila.
*/

int main() {
    stack<int> pila;
    pila.push(21);
    pila.push(22);
    pila.push(24);
    pila.push(25);
     
    pila.pop();
    pila.pop();
 
    while (!pila.empty()) {
        cout << ' ' << pila.top();
        pila.pop();
    }
}