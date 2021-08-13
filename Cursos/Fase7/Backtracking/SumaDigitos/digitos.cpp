/*
  Link: https://omegaup.com/arena/problem/Suma-de-digitos/#problems
  Solucion: Recursividad
  Contar todas las soluciones.

  Ejecutar: g++ -std=c++11 digitos.cpp -o digitos && ./digitos < digitos.in > digitos.out
*/
#include<bits/stdc++.h>

using namespace std;

int busqueda(int sumaActual, int sumaABuscar) {

  // comprobar si la suma actual es la suma a buscar
  // si es asi, incrementamos nuestra variable como una posible solución.
  // no olvidemos hacer el return para salirnos de la ejecución.
  if (sumaActual == sumaABuscar) {
    return 1;
  }
  
  // Probar los diferentes digitos del 0-9 para seguir buscando la sumatoria
  int respuestas = 0;
  for (int i = 1; i<=9; i++) {
    int candidato = sumaActual + i;
    if (candidato > sumaABuscar) {
      continue;
    } else {
      respuestas += busqueda(candidato, sumaABuscar);
    }
  }

  return respuestas;
}


int main() {
  
  int n;
  cin >> n;

  int soluciones = busqueda(0, n);
  cout<<soluciones<<endl;

  return 0;
}