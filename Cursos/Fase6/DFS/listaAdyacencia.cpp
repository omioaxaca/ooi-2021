/*
  Grafos con Lista de Adyacencia
*/

#include<bits/stdc++.h>
using namespace std;

typedef vector<vector<int> > listaAdyacencia;
 
// Función para crear una conexión en el grafo.
void agregarArista(listaAdyacencia &lista, int vertice1, int vertice2) {
  lista[vertice1].push_back(vertice2);
  lista[vertice2].push_back(vertice1);
}
 
// Función recursiva para recorrer el grafo.
void dfs(int vertice, listaAdyacencia &lista, vector<bool> &visitado) {
  visitado[vertice] = true;
  cout << vertice << " ";
  for (int i=0; i < lista[vertice].size(); i++) {
    if (visitado[lista[vertice][i]] == false) {
      dfs(lista[vertice][i], lista, visitado);
    }
  }
}

// Función que corre la busqueda desde los vertices que no han sido visitados.
void busca(listaAdyacencia &lista, int vertices) {
  vector<bool> visitado(vertices, false);
  for (int vertice=0; vertice < vertices; vertice++) {
    if (visitado[vertice] == false) {
      dfs(vertice, lista, visitado);
    }
  }
}

int main() {
  int vertices = 5;
  listaAdyacencia lista = listaAdyacencia(vertices, vector<int>());

  // los vertices deben de ser en un rango de [0, vertices-1]
  agregarArista(lista, 0, 1);
  agregarArista(lista, 0, 4);
  agregarArista(lista, 1, 2);
  agregarArista(lista, 1, 3);
  agregarArista(lista, 1, 4);
  agregarArista(lista, 2, 3);
  agregarArista(lista, 3, 4);

  busca(lista, vertices);

  return 0;
}