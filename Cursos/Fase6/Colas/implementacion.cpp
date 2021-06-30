#include <bits/stdc++.h>

using namespace std;

const int TAM = 100;

// Arreglo para almacenar la informacion de la cola.
vector<int> cola(TAM);
// Indices para controlar el frente y detras de la cola.
int indice_front = 0;
int indice_tail = 0;

void push(int x) {
    cola[indice_tail] = x;
    indice_tail++;
}

int front() {
    return cola[indice_front];
}

void pop() {
    indice_front++;
}

int size() {
    return indice_tail - indice_front;
}

bool empty() {
    return size() == 0;
}

int main () {
    push(1);
    push(2);
    push(3);
    push(4);

    pop();

    cout << "size: " << size() << "\n";

    while (!empty()) {
        cout << front() << " ";
        pop();
    }

    return 0;
}