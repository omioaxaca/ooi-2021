#include <bits/stdc++.h>

using namespace std;

int main() {
    long long N;
    int A, B, C, D, E, F;

    cin >> N >> A >> B >> C >> D >> E >> F;

    // Obtenemos la suma mínima para 1, 2 y 3
    // También podemos hacerlo con condicionales IF
    // Pero para reducir código usamos la función "min" que te devuelve el mínimo de dos valores

    // Obtenemos el mín de una cara
    int min_1c = min(A, B);
    min_1c = min(min_1c, C);
    min_1c = min(min_1c, D);
    min_1c = min(min_1c, E);
    min_1c = min(min_1c, F);

    // Obtenemos el mín de dos caras
    int min_2c = A+B;
    min_2c = min(min_2c, A+C);
    min_2c = min(min_2c, A+D);
    min_2c = min(min_2c, A+E);
    min_2c = min(min_2c, B+C);
    min_2c = min(min_2c, B+D);
    min_2c = min(min_2c, B+F);
    min_2c = min(min_2c, C+E);
    min_2c = min(min_2c, C+F);
    min_2c = min(min_2c, D+E);
    min_2c = min(min_2c, E+F);

    // Obtenemos el mín de tres caras
    int min_3c = A+B+C;
    min_3c = min(min_3c, A+B+D);
    min_3c = min(min_3c, A+C+E);
    min_3c = min(min_3c, A+E+D);
    min_3c = min(min_3c, F+B+C);
    min_3c = min(min_3c, F+B+D);
    min_3c = min(min_3c, F+C+E);
    min_3c = min(min_3c, F+E+D);

    // si N == 1 la cara con el valor más alto no debe verse
    if (N == 1) {
        // Calculamos cual es la cara máxima
        int max_1c = max(A, B);
        max_1c = max(max_1c, C);
        max_1c = max(max_1c, D);
        max_1c = max(max_1c, E);
        max_1c = max(max_1c, F);
        // Imprimimos la suma total menos la cara con el valor más alto
        cout << A + B + C + D + E + F - max_1c;

        // terminamos el programa
        return 0;
    }

    // Nota que N es de tipo long long, como N < 1000000  entonces (N-2)^2 < 1000000000000 -2N + 4
    // Lo cual ya no cabe en un tipo entero

    // El número de cubos de una cara
    long long cubos_1c = (N-2) * (N-2) * 5 + (N-2) * 4;
    // El número de cubos de dos caras
    long long cubos_2c = (N-2) * 8 + 4;
    // El número de cubos de 3 caras
    long long cubos_3c = 4;

    long long total = cubos_1c * min_1c + cubos_2c * min_2c + cubos_3c * min_3c;

    cout << total << endl;

    return 0;
}
