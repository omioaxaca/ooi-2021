# Problema F Estaciones de Radio

**Descripción**: https://omegaup.com/arena/problem/estacion

En encontrar la estación de radio más cercana de las 5 estaciones que nos proporcionan dado una frecuencia inicial en particular.

Si la frecuencia inicial no está dentro del rango imprimimos la palabra "error", si no, imprimimos la distancia la frencuencia más cercana y si está adelante o detrás.

Nota: Si hay dos estaciones a la misma distancia debemos tomar la más a la derecha.


## Solución

- Para solucionar el problema basta con calcular la distancia a cada estación y quedarnos con la que más pequeña.
- Para quedarnos con la más a la derecha en caso de que haya distancias iguales basta con recorren las estaciones en orden ascendente y usar $<=$ a nuestra comparación.
- Usamos el signo de la distancia para saber si está a la derecha o izquierda

## Código

```c++
#include <bits/stdc++.h>

using namespace std;

int main() {
    // Señales para cada estación de radio
    int radio_karel = 580;
    int radio_z = 980;
    int radio_java = 1190;
    int radio_beta = 1250;
    int radio_sabro = 1420;

    // Leemos la frecuencia actual
    int actual_frec = 0;
    cin >> actual_frec;

    // Verificamos que si no está en el rango imprimimos "error" y terminamos la ejecución
    if (actual_frec < 540 || actual_frec > 1520) {
        cout << "error\n";
        return 0;
    }

    // Asignamos la distancia mínima a movernos como un número grande
    // en este caso podemos usar la señal más grande
    int frec_dist = radio_sabro;

    // Preguntamos por cada estación si la distancia a esta es menor o igual que la distancia
    // mínima actual. Si es así nos quedamos con esta distancia
    // Al preguntar en orden acendente las frecuencias y por nuestra condicion de menor o gual
    // aseguramos quedarnos con la estación más a la derecha en caso que las distancias
    // sean iguales

    if (abs(radio_karel - actual_frec) <= abs(frec_dist)) {
        frec_dist = radio_karel - actual_frec;
    }

    if (abs(radio_z - actual_frec) <= abs(frec_dist)) {
        frec_dist = radio_z - actual_frec;
    }

    if (abs(radio_java - actual_frec) <= abs(frec_dist)) {
        frec_dist = radio_java - actual_frec;
    }

    if (abs(radio_beta - actual_frec) <= abs(frec_dist)) {
        frec_dist = radio_beta - actual_frec;
    }

    if (abs(radio_sabro - actual_frec) <= abs(frec_dist)) {
        frec_dist = radio_sabro - actual_frec;
    }

    // Si la distancia es mayor a cero quiere decir que la estación está adelante
    if (frec_dist > 0) {
        cout << "adelante ";
    } else {
        cout << "atras ";
    }

    cout << abs(frec_dist) << endl;

    return 0;
}

```

