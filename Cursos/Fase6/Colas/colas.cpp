#include <iostream>
#include <queue> // Cola = queue 

using namespace std;

/*
  Estructura de datos para almacenar información con el metodo FIFO 
  (Frist In First Out) (Primero en entrar - Primero en salir)


  Funciones de queue:
  push(T x) =  Añade el elemento x al final de la cola O(1)
  front()   =  Acceder al elemento al frente de la cola O(1)
  pop()     =  Eliminar (sacar) el elemento del frente de la cola O(1)
  empty()   =  Regresa un TRUE si la cola esta vacia y un FALSE si tiene elementos O(1)
  size()    =  Regresa un entero con el numero de elementos dentro de la cola O(1)
*/

int main() {
    queue<int> cola;
    cola.push(21); // 21
    cola.push(22); // 21, 22
    cola.push(24); // 21, 22, 24
    cola.push(25); // 21, 22, 24, 25
     
    cola.pop(); // 22, 24, 25
    cola.pop(); // 24, 25
 
    while (!cola.empty()) {
        cout << ' ' << cola.front();
        cola.pop();
    }
}