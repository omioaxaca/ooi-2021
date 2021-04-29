// Lista implementacion manual
// Funciones a implementar
// push_back(int x)
// erase() // elimina el primer elemento
// remove(int x) // elimina todos los elementos iguales a x
// int size() // tamanio de la lista
#include <bits/stdc++.h>

using namespace std;

struct NodoLista {
    // Miembros de la estructura
    int val;
    NodoLista* sig;

    // Constructor
    NodoLista(int x) {
        val = x;
        sig = NULL;
    }

    // Funciones
    bool operator<(NodoLista rhs) {
        return val < rhs.val;
    }
};

// Declarar la lista
NodoLista* miLista = NULL;
NodoLista* tail = NULL;

// Crea un nodo inicial para la lista
void init(int x) {
    miLista = new NodoLista(x);
    // Tail apunta al final, que por el momento es igual
    // al principio
    tail = miLista;
}

void push_back(int x) {
    // Crear un nuevo nodo con el valor de x
    NodoLista* nuevo = new NodoLista(x);
    // Hacer que el final de la lista apunte a nuevo
    tail->sig = nuevo;
    // Recorrer el final de la lista.
    tail = nuevo;
}

void erase() {
    // Guardar el nodo del inicio
    NodoLista* actual = miLista;
    // Hacer que el inicio apunte al siguiente
    miLista = miLista->sig;
    // Borrar el que era el inicio
    delete actual;
}

// Imprimir toda la lista
void print() {
    NodoLista* actual = miLista;
    while (actual != NULL) {
        cout << actual->val << " ";
        actual = actual->sig;
    }
}


int main() {
    for (int i = 0; i < 10; ++i) {
        if (i == 0) {
            init(i);
        }
        else {
            push_back(i);
        }
    }
    print();
    cout << "\n";
    erase();
    erase();
    print();

    return 0;
}