# Problema M Si te da

**Descripción**: https://omegaup.com/arena/problem/siteda

El problema consiste en iterar sobre una secuencia cuyo siguiente elemente está formado por tomar la unidad del resultado de la suma de los dos anteriores.

La secuencia termina cuando volvamos a los dos primeros números iniciales.

Debemos imprimir la secuencia y el número de elementos formados.


## Solución

- Para solucionar el problema podemos simular la secuencia.
- Usaremos el operador de módulo para obtener el siguiente elemento.
- Para imprimir la secuencia podemos hacerlo por partes, es decir, al  generar cada elemento de la secuencia.
- Observa que usamos una variable auxiliar $tmp$ para no perder níngún elemento de la secuencia.

## Código

```c++
#include <bits/stdc++.h>

using namespace std;

int main() {
    // Nuestros dos primeros número de la secuencia
    int num1 = 0;
    int num2 = 0;

    cin >> num1;
    cin >> num2;

    // Variables auxialiares para la simulación del proceso
    // current y neext nos ayudan a guardar los dos últimos número de la secuencia
    int current = num1;
    int next = num2;
    int count = 0;

    // Imprimimos los dos primeros números generados
    cout << num1 << " " << num2;

    while (true) {
        // Calculamos el siguiente número
        int tmp = (current + next) % 10;
        // Actualizamos los valores de nuestros dos últimos números generados hasta el momento
        current = next;
        next = tmp;

        // Contamos
        count++;

        // Imprimimos el siguiente número de la secuencia
        cout << " " << next;

        // Cuando hayamos regresado al inicio de la secuencia terminamos el ciclo
        if (current == num1 && next == num2) {
            break;
        }
    }

    cout << endl << count << endl;

    return 0;
}

```
