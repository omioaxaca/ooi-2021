# Problema Maxima Calificación

**Descripción**: https://omegaup.com/arena/problem/Maxima-calificacion/

El problema consiste en dado 3 numeros encontrar el mayor de los 3


## Solución

la solución al problema es comparar los 3 numeros 
a > b y a > c  => a es mayor 
b > a y b > c => b es mayor
si no c es mayor


## Código

```c++
#include <bits/stdc++.h>

using namespace std;

int main () {
  int a, b, c;
  cin >> a;
  cin >> b;
  cin >> c;

  if( a > b && a > c){
    cout << a << endl;
  } else if (b > a && b > c){
    cout << b << endl;
  }else {
    cout << c << endl;
  }

 return 0;

}

```
