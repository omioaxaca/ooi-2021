/*+
  * Problemas M Si te da
  * https://omegaup.com/arena/problem/siteda
  *
  **/

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
