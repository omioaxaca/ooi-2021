# Normal

## Descripción

Dada la descripción tenemos que simular una distribución normal con números enteros.
Como entrada tenemos un número N que indica el máximo de la distribución. Tenemos que empezar desde
1 hasta N y una vez llegado a N tenemos que ir de N a 1. De esa manera podemos imprimir en pantalla
la distribución de 1 hasta N y de N hasta 1.

## Código

```c++
  #include <iostream>

  using namespace std;

  int main() {
    int max;
    cin >> max;
    int i;
    for(i = 1; i <= max; i++) {
      cout << i << ' ';
    }
    for (i = max - 1; i >= 1; i--) {
      cout <<  i << ' ';
    }
  }
```
