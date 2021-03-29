# Problema E pb Bardeando

**Descripción**: https://omegaup.com/arena/problem/pb-Bardeando/

El problema consiste en calcular la cantidad faltante de longitud de trozos para cubrir cierto perímetro.

Nos dan $n$ trozos y cada trozo tiene cierta longitud.


## Solución

- Debemos sumar la cantidad de perímetro que podemos cubrir, para ello usamos un ciclo.
- Calculamos la diferencia $Perimetro - suma$. Si la diferencia es negativa tenemos de sobra.

## Código

```c++
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

```
