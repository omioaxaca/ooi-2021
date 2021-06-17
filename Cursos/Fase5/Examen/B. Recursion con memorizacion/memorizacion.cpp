// https://omegaup.com/arena/ooi-2021-e3/admin/#problems/Recursion-con-memorizacion
// NOTA: Esta implementacion usa arreglos y variables globales, pero una mejor practica
// seria pasarlos por referencia en la funcion.
#include <bits/stdc++.h>

using namespace std;

// Usar el typedef para evitar escribir el nombre largo del tipo de dato.
// En su lugar usaremos u64. Es decir, es como usar un alias.
typedef unsigned long long int u64;

// Definir las matrices auxiliares para la memoria y los estados visitados/usados.
u64 memo[101][101][101] = {0};
bool visitado[101][101][101] = {false};
// Variable global para contar las llamadas unicas.
int llamadasUnicas = 0;

// Funcion auxiliar para retornar el menor entre 3 numeros.
u64 minimo(int a, int b, int c) {
    return min(a, min(b, c));
}

u64 f(int a, int b, int c) {
    // Si el estado ya se visito, entonces retornar el valor almacenado en la memoria.
    if (visitado[a][b][c]) {
        return memo[a][b][c];
    }
    // Revisar casos base y paso recursivo
    u64 resultado;
    if (minimo(a, b, c) <= 3) {
        resultado = a + 2*b + 3*c;
    }
    else if (a + b + c == 100){
        resultado = 0;
    }
    else {
        resultado = f(a - 1, b - 1, c - 1) + f(a, b - 3, c - 3) + f(a / 2, b, c);
    }
    // Marcar el estado como visitado y almacenarlo en la memoria.
    memo[a][b][c] = resultado;
    visitado[a][b][c] = true;
    // Actualizar la cantidad de llamadas unicas
    llamadasUnicas++;
    return memo[a][b][c];
}

int main() {
    int a;
    int b;
    int c;
    cin >> a >> b >> c;

    cout << f(a, b, c) << " " << llamadasUnicas;

    return 0;
}