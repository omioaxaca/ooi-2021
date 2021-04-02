# El caracol

## Descripción

Nos dicen que el caracol tiene que subir una cantidad P de metros para salir de un pozo.
Todos los días logra subir S metros y cada noche resbala R metros. Por lo que tenemos que
calcular en cuantos días podría salir del pozo.

## Solución

Tenemos que hacer un ciclo en el que cada iteración corrresponde a un día y una noche.
Continuaremos el ciclo mientras la cantidad de metros avanzada sea menor que la profundidad del pozo.
Si el caracol no ha podido salir, tenemos que restar los metros que éste resbala cada noche.

## Código

```c++
  #include <iostream>

  using namespace std;

  int main() {
    int profundidad, sube, resbala, metrosSubidos;
    cin >> profundidad >> sube >> resbala;
    int dias = 0;

    while(metrosSubidos < profundidad) {
      dias++;
      metrosSubidos += sube;
      if (metrosSubidos < profundidad) {
        metrosSubidos -= resbala;
      }
    }

    cout << dias;
  }
```
