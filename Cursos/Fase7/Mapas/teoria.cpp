#include <bits/stdc++.h>
// #include <map> En caso de no usar BITS

using namespace std;
/*
  Mapas
*/
int main() {

  // definicion de un mapa.
  // El primer tipo de dato es para la llave y el segundo para el valor.
  
  // MAPA
  // Self Balancing Binary Search Tree
  // Tiempo de busqueda O(log n), O(1) 
  // Las llaves se encuentran ordenadas.
  map<int, char> mapa; 

  // UNORDERED MAP:
  // Hash Table 
  // Tiempo de busqueda O(1),   Peor Caso O(N)
  // No se encuentran ordenadas.
  unordered_map<int, char> mapaNoOrdenado;

  // agregar elementos al mapa.
  mapa[5] = 'e';
  mapa[3] = 'c';
  mapa[4] = 'd';
  mapa[1] = 'a';
  mapa[2] = 'b';

  // preguntar si el mapa contiene un elemento, del conjunto de elementos que agregamos.
  // Complejidad O(1)
  if (mapa.find(1) != mapa.end()) {
    // hemos encontrado el elemento 1.
    char valor = mapa[1];
  }

  // Iterar el mapa 
  // 1. Usando un iterador del mapa.
  /*
  for (map<int, char>::iterator it = mapa.begin(); it != mapa.end(); it++) {
    int llave = it->first;
    char valor = it->second;
  }
  */
  // 2. Usando un auto iterador
  for (auto it: mapa) {
    int llave = it.first;
    char valor = it.second;

    cout<<llave<<" - "<<valor<<endl;
  }

  // Contar elementos del mapa.
  int tamano = mapa.size();

  // Saber si el mapa esta vacio.
  bool estaVacio = mapa.empty();


  return 0;
}
