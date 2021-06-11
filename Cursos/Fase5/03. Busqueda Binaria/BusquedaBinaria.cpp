#include <bits/stdc++.h>

using namespace std;

/*
Esta funcion de busqueda binaria nos regresa el indice del elemento que estamos buscando en el Arreglo.
Para que funcione al Arreglo debe de estar ordenado.
Complejidad o(log2n)
*/
int busqueda_binaria(vector<int>& arreglo, int x) {
  int ini = 0;
  int fin = arreglo.size()-1;

  // mientras nuestros dos indices no se junten.
  while(ini <= fin) {
    int mid = ini + (fin - ini) / 2; // calculamos el indice de la mitad de nuestro rango [ini,fin]

    if (arreglo[mid] == x) { // Hemos encontrado el elemento x en el arreglo
      return mid;
    }

    if (arreglo[mid] > x) { // el valor en mid es mas grande que x, nos tenemos que ir a la izquierda.
      fin = mid - 1;
    } else if (arreglo[mid] < x) {// el valor en mid es mas pequeño que x, nos tenmos que ir a la derecha.
      ini = mid + 1;
    }

  }

  return -1; // si se rompe el ciclo y no se retorno la respuesta quiere decir que no encontramos nada.
}

int main() {
  vector<int> arreglo;

  for (int i=0; i<20; i++) {
    arreglo.push_back(i);
  }

  int buscar = 10;
  int indice = busqueda_binaria(arreglo, buscar);

  if (indice != -1) {
    cout<<"Hemos encontrado el numero en el arreglo";
  } else {
    cout<<"El numero no se encuentra en el arreglo";
  }
}