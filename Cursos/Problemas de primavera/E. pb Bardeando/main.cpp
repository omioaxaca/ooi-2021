/*+
  * Problemas E pb Bardeando
  * https://omegaup.com/arena/problem/pb-Bardeando/
  *
  **/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int perimetro = 0;
    int n_trozos = 0;
    int suma = 0;
    int s_trozo = 0;

    cin >> perimetro;
    cin >> n_trozos;

    // Leemos el tamaño de cada trozo y lo sumamos
    while (n_trozos > 0) {
        cin >> s_trozo;
        suma +=  s_trozo;
        n_trozos--;
    }

    // Calculamos la cantidad restante
    int restantes = perimetro - suma;

    // Si lo restante es menor a cero entonces tenemos trozos de sobra
    // Y no nos resta nada
    if (restantes < 0) {
        restantes = 0;
    }

    cout << restantes << endl;

    return 0;
}
