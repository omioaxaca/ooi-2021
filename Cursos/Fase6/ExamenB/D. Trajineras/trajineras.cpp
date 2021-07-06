#include <bits/stdc++.h>

using namespace std;

typedef long long int i64;

// Declara los arreglos para almacenar el peso de los robots y el arreglo de precalculo.
vector<int> robots;
vector<i64> sumas;

// Precalcula las sumas acumulativas del peso de los robots contiguos. Esto es util para
// evitar volver a calcular los valores cada vez.
// En otras palabras, el valor de sumas[i] equivale a la suma de los pesos desde el inicio
// hasta i.
// sumas[i] = sumatoria(0, i)
void precalcularSumatorias() {
    for (int i = 0; i < robots.size(); ++i) {
        sumas[i] = robots[i];
        if (i > 0) {
            sumas[i] += sumas[i - 1];
        }
    }
}

// Regresa la suma de los pesos en el rango [ini, fin]
// Si se utiliza la expresion sumatoria(y) - sumatoria(x), donde x <= y se obtiene el valor de la sumatoria entre el
// rango (x, y], nota que x es exclusive. Para hacerlo inclusive, se utilizaria sumatoria(y) - sumatoria(x - 1)
i64 sumatoriaEnRango(int ini, int fin) {
    if (ini > 0) {
        return sumas[fin] - sumas[ini - 1];
    }
    return sumas[fin];
}

// Regresa verdadero si es posible formar grupos de robots continuos de tamanio tamGrupo sin exceder
// la carga total en ningun momento para cada grupo.
bool esPosibleFormarGruposSinExcederCarga(int tamGrupo, i64 cargaTotal) {
    if (tamGrupo == 0) {
        return true;
    }
    for (int i = 0; i <= robots.size() - tamGrupo; ++i) {
        if (sumatoriaEnRango(i, i + tamGrupo - 1) > cargaTotal) {
            return false;
        }
    }
    return true;
}

// Busca el tamanio maximo del grupo de robots contiguos, cuyo peso no excede la carga total.
// Implementa una busqueda binaria (upper_bound) para probar de manera optima los valores posibles del rango.
int buscarTamanioGrupo(i64 cargaTotal) {
    int ini = 0; // El minimo posible es equivalente a un grupo de tamanio 1.
    int fin = robots.size(); // El maximo posible es equivalente a un grupo que incluye todos los robots.
    while (ini < fin) {
        int mitad = ini + (fin - ini + 1) / 2;
        if (esPosibleFormarGruposSinExcederCarga(mitad, cargaTotal)) {
            ini = mitad;
        }
        else {
            fin = mitad - 1;
        }
    }
    return ini;
}

int main() {
    int numRobots;
    i64 cargaTotal;
    
    cin >> numRobots >> cargaTotal;
    // Asignar el tamanio adecuado a los vectores
    robots.resize(numRobots);
    sumas.resize(numRobots);

    for (int i = 0; i < numRobots; ++i) {
        cin >> robots[i];
    }

    precalcularSumatorias();
    cout << buscarTamanioGrupo(cargaTotal);

    return 0;
}