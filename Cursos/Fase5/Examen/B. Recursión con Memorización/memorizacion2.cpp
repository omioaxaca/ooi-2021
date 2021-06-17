// https://omegaup.com/arena/problem/Recursion-con-memorizacion
#include <bits/stdc++.h>

using namespace std;


typedef unsigned long long int u64;

// Estructura para representar los estados de la función
typedef pair<int, pair<int, int>> State;

// Definimos la memoria como un mapa con claves de tipo State y
// valores tipo u64
map<State, u64> MEM;
int TOTAL = 0;

u64 f(int a, int b, int c) {
    // Creamos el estado
    State s = make_pair(a, make_pair(b, c));

    // Preguntamos si existe en la memoria
    if (MEM.find(s) != MEM.end()) {
        return MEM[s];
    }

    // Contamos el total de llamadas únicas
    TOTAL++;

    // Guardamos en memoria el valor para cada caso
    if (min(a, min(b, c)) <= 3) {
        MEM[s] = a + 2*b + 3*c;
    } else if (a + b + c == 100) {
        MEM[s] = 0;
    } else {
        MEM[s] = f(a-1, b-1, c-1) + f(a, b-3, c-3) + f(a/2, b, c);
    }

    return MEM[s];
}


int main() {
    int a, b, c;

    cin >> a >> b >> c;

    cout << f(a, b, c) << " " << TOTAL << endl;

    // También podemos imprimir el tamaño de nuestra memoria para contabilizar
    // las llamadas únicas
    // cout << f(a, b, c) << " " << MEM.size() << endl;

    return 0;
}
