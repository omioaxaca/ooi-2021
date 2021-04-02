# Problema F Estaciones de Radio

**Descripción**: https://omegaup.com/arena/problem/nofib/#problems

El problema consiste en dado un numero entero 'a' escribir todos los numeros menores a 'a' que no pertenecen a la susesion


## Solución

- hay que primero encontrar los numeros que si pertenecen a la sucesion
- debemos guardar el valor anterior de la suma así como el nuevo valor de la suma
- usamos estos 2 valores como rango para  imprimir  los valores que no se encuentran en la sucesion simpre y cuando el valor sea menor al que nos indicaron 


## Código

```c++
#include <bits/stdc++.h>

using namespace std;

int main () {
  int a;
  cin >> a;
  int anteriorNum = 2;
  int nuevoNum = 3;
  int fibo = 0;

  while(fibo < a){ // condicion de paro de nuestro ciclo while 
    fibo = anteriorNum + nuevoNum; // obtenemos el valor de la sucesion
    anteriorNum = nuevoNum;// guardamos la suma mas reciente
    nuevoNum = fibo;// asignamos la nueva suma
    
    //usamos como rango anteriorNum y nuevoNum para saber que numeros no estan incluidos 
    for(int i = anteriorNum + 1 ; i < nuevoNum ; i++){
        if( i < a ){ //imprimimos el numero simpre y cuando sea menor a 'a'
          cout << i << " "; 
        }
      }
  }
 return 0;

}

```
