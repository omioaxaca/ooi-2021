
#include <bits/stdc++.h>

using namespace std;

int main() {

  //Declaración de vectores
  int vector1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  string vector2[2] = {"Hola", ""};

  // true = 1 false = 0 
  bool vector3[4] = {true};

  cout << "Esto es un booleano " <<  (1 < 2) << endl;

  //como acceder  a los valores de un vector
  cout  << vector1[4] << endl;
  cout << vector2[1] << endl;
  cout << vector3[1] << endl;
  cout << vector3[0] << endl;

  int v1 [3] = {1, 2, 3};
  double v2 [3] = {4.34, 5.90, 9.09};
  string v3 [3] = {"Hola", "Mundo", "Adios"};

  cout << v1[1] << endl;
  cout << v2[0] << endl;
  cout << v3[2] << endl;

  // modificar los valores de un vector
  v1[1] = 10;
  v2[0] = 12;
  v3[2] = true;

  cout << v1[1] << endl;
  cout << v2[0] << endl;
  cout << v3[2] << endl;

  
  // sumar los elementos de un vector
  int sumaArreglo = 0;
  for(int i = 0; i < 10 ; i++) {
    cout << vector1[i] << " " ;
    sumaArreglo += vector1[i]; // sumaArreglo = sumaArreglo + vector1[i]
  }

  cout << "suma de vector "  << sumaArreglo << endl;

  cout << endl;

  //recorrer el vector de derecha a izquierda 
  for( int i = 9 ; i >= 0 ; i--){
    cout << vector1[i] << " ";
  }

  cout << endl;

  //obtener el tamaño del vectro
  int tamano = sizeof vector1 / sizeof(int);

  cout << "tamaño = "<< tamano << endl;

  int suma = v1[0] + vector1[4];
  cout << suma << endl;


 cout << "tamaño de vector double " << (sizeof v2 / sizeof(double)) << endl;
  cout << "sizeof  " << sizeof 1 << endl;
  cout << "sizeof vector1 " << sizeof vector1 << endl;
}