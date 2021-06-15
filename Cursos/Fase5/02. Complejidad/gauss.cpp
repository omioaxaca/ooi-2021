// https://omegaup.com/course/ooi_2021_fase_456/assignment/semana-6/admin/#problems/Sumas-de-Gauss
#include <bits/stdc++.h>

using namespace std;

// Regresar la suma de los numeros del 1 al n
long long int suma_gauss(long long int n) {
    long long int suma = 0;
    // El metodo de iterar del 1 al n es muy lento.
    // for (int i = 1; i <= n; ++i) {
    //     suma += i;
    // }
    
    // Utilizando la propiedad de Gauss se puede hacer constante
    suma = (n * (n + 1))/2;
    return suma;
}

int main() {
    int p;
    cin >> p;

    double resultado = 0;
    // Aplicar las operaciones de divisiones a las parejas de numeros
    for (int i = 1; i <= p; i += 2) {
        resultado += (suma_gauss(i) / (double)suma_gauss(i + 1));
    }
    cout << fixed << setprecision(3) << resultado << "\n";
    
    return 0;
}