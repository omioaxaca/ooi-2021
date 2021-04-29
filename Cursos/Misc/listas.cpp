#include <bits/stdc++.h>

using namespace std;

int main() {
    list<int> mi_lista; // Declarar una lista doblemente ligada
    // 1 -> 2 -> 3 -> NULL
    mi_lista.push_back(1);
    mi_lista.push_back(2);
    mi_lista.push_back(3);
    mi_lista.push_back(3);

    // Una lista no se puede indexar
    list<int>::iterator it = mi_lista.begin(); // Crear un iterador al inicio de la lista
    cout << *it << " "; // Imprimir el valor del inicio
    it++; // Avanzar a la siguiente posicion de la lista
    cout << *it << " ";
    it--;
    cout << *it << " ";
    cout << endl;

    // Imprimir todos los elementos de la lista usando un iterador
    for (list<int>::iterator it = mi_lista.begin(); it != mi_lista.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Imprimir los elementos con un for automatico
    for (auto& v : mi_lista) {
        cout << v << "\n";
    }
    cout << endl;

    // Eliminar el primer elemento
    mi_lista.erase(mi_lista.begin());

    // Eliminar un elemento con un determinado valor
    mi_lista.remove(3); // Elimina todo lo que tiene el numero 3

    return 0;
}
