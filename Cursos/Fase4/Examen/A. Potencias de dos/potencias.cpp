// https://omegaup.com/arena/problem/ptwo#problems
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> digitos;
    digitos.push_back(1); // Iniciar con el numero 1, el cual equivale a 2 a la 0 potencia.

    // Multiplicar el numero por 2 durante n veces
    //    Nota que representamos los digitos al revés dentro del vector para facilitar insertar digitos usando push_back,
    //    es decir el numero 17628, se representaria en el vector como {8, 2, 6, 7, 1}.
    for (int iteracion = 0; iteracion < n; ++iteracion) {
        // Recorre el vector multiplicando cada elemento de izquierda a derecha (recuerda que los digitos estan al revés)
        int acarreo = 0;
        for (int i = 0; i < digitos.size(); ++i) {
            int resultado = digitos[i] * 2 + acarreo; // El resultado es el digito multiplicado por 2 más el acarreo existente
            digitos[i] = resultado % 10; // Solo almacenar la unidad
            acarreo = resultado / 10; // Actualizar el acarreo
        }
        // Si al final de multiplicar los digitos existe acerreo, entonces agregarlo al vector.
        if (acarreo > 0) {
            digitos.push_back(acarreo);
        }
    }

    // Imprimir el resultado, digito por digito empezando de derecha a izquierda, ya que los digitos estan al revés
    for (int i = digitos.size() - 1; i >= 0; --i) {
        cout << digitos[i];
    }

    return 0;
}