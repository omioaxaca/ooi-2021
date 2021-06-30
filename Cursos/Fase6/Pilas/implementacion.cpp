#include <bits/stdc++.h>

using namespace std;

const int TAM = 100;

// Arreglo para almacenar la informacion de la pila.
vector<int> pila(TAM);
// Indice para tener control de donde guardar la informacion en la pila.
int indice_top = 0;

void push(int x) {
    pila[indice_top] = x;
    indice_top++;
}

int top() {
    return pila[indice_top - 1];
}

void pop() {
    indice_top--;
}

int size() {
    return indice_top;
}

bool empty() {
    return size() == 0;
}

int main() {
    push(1);
    push(2);
    push(3);
    push(4);

    pop();

    cout << "tam: " << size() << "\n";

    while (!empty()) {
        cout << top() << " ";
        pop();
    }

    return 0;
}