# Codigo visto en la clase de vectores 22-04-2021



## descripción 
En esta clase vimos la clase vector y algunas de sus metodos como 'size, end, begin'

## Código de la clase

```c++


#include <bits/stdc++.h>

using namespace std;

int main() {

  int numeroDatos;
  string dato;

  // {6, 3, 5, 1}
  vector<int> numeros;
  numeros.push_back(6);
  numeros.push_back(3);
  numeros.push_back(5);
  numeros.push_back(10);
  numeros.push_back(11);
  numeros.push_back(20);
  numeros.push_back(90);
  numeros.push_back(74);

  cin >> numeroDatos;
  for(int i = 0; i < numeroDatos; i++){
    cin >> dato;
    numeros.push_back(dato);
  }

  // ordenar el arreglo 
  sort(numeros.begin(), numeros.end());

  //recorrer el arreglo  
  // .size() es para obtener el tamaño del arreglo
  for(int i = (numeros.size() - 1) ; i >= 0 ; i--){
    cout  << numeros[i] << " ";
  }



  //6 74
  //3 90
  //5 20
  //10 11


  int tamano = numeros.size();
  int resto = tamano/2;
  for(int i = 0 ; i <= resto ; i++){
      if(tamano % 2 == 0 && i < resto - 1){
        cout << numeros[i] << " " << numeros[(tamano - i) - 1] << endl;
      }else if (i != resto){
        cout << numeros[i] << " " << numeros[(tamano - i) - 1] << endl;
      } else if(tamano % 2 == 1){
        cout << numeros[i] << endl;
      }
  }
}

```
