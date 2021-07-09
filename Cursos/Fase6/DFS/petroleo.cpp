/*
  https://omegaup.com/arena/problem/COMI-Derrame-de-Petroleo
  Solución:  DFS al 80%.
  
  Esta es la mejor solución que se puede lograr con DFS, dada la naturaleza del problema.
  Es mejor usar BFS.
*/

#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<char> > matriz;

/*
  compilar con la bandera de C++11 para que funcione la declaración de estos vectores.
  g++ -std=c++11 petroleo.cpp -o petroleo && ./petroleo
*/
vector<int> fils = { -1, 0, 1, 0 };
vector<int> cols = { 0, 1, 0, -1 };

void dfs(int i, int j, int nivel, int dias, matriz &oceano) {
  if (nivel > dias) {
    return;
  }

  oceano[i][j] = '*';

  for (int v=0; v<4; v++) {
    int nuevaI = i + fils[v]; 
    int nuevaJ = j + cols[v];

    // comprobar que las nuevas coordenadas del vecino a visitar no se salgan de los bordes
    // de la matriz. 
    if (nuevaI >= 0 && nuevaI < oceano.size() && nuevaJ >= 0 && nuevaJ < oceano[nuevaI].size()) {
      // podemos visitar este vecino.
      if (oceano[nuevaI][nuevaJ] == '.' && nivel + 1 <= dias) {
        dfs(nuevaI, nuevaJ, nivel + 1, dias, oceano);
      }
    }
  }
}

void realizarBusqueda(int i, int j, int dias, matriz &oceano) {
  // desde i, j, explorar a los vecinos y por cada vecino invocar la recursividad.
  for (int v=0; v<4; v++) {
    int nuevaI = i + fils[v]; 
    int nuevaJ = j + cols[v];

    // comprobar que las nuevas coordenadas del vecino a visitar no se salgan de los bordes
    // de la matriz. 
    if (nuevaI >= 0 && nuevaI < oceano.size() && nuevaJ >= 0 && nuevaJ < oceano[nuevaI].size()) {
      // podemos visitar este vecino.
      if (oceano[nuevaI][nuevaJ] == '.') {
        dfs(nuevaI, nuevaJ, 1, dias, oceano);
      }
    }
  }
}

struct nodo {
  int i;
  int j;
  int nivel;
};
void realizarBusquedaIterativa(int i, int j, int dias, matriz &oceano) {
  stack<nodo> pila;
  for (int v=0; v<4; v++) {
    int nuevaI = i + fils[v]; 
    int nuevaJ = j + cols[v];

    if (nuevaI >= 0 && nuevaI < oceano.size() && nuevaJ >= 0 && nuevaJ < oceano[nuevaI].size()) {
      if (oceano[nuevaI][nuevaJ] == '.') {
          nodo inicio;
          inicio.i = nuevaI;
          inicio.j = nuevaJ;
          inicio.nivel = 1;
          pila.push(inicio);
      }
    }
  }

  while(!pila.empty()) {
    nodo actual = pila.top();
    pila.pop();

    if (actual.nivel > dias) {
      continue;
    }

    oceano[actual.i][actual.j] = '*';

    for (int v=0; v<4; v++) {
      int nuevaI = actual.i + fils[v]; 
      int nuevaJ = actual.j + cols[v];
      if (nuevaI >= 0 && nuevaI < oceano.size() && nuevaJ >= 0 && nuevaJ < oceano[nuevaI].size()) {
        if (oceano[nuevaI][nuevaJ] == '.' && actual.nivel + 1 <= dias) {
          nodo vecino;
          vecino.i = nuevaI;
          vecino.j = nuevaJ;
          vecino.nivel = actual.nivel + 1;          
          pila.push(vecino);
        }
      }
    }
  }
}

int main () {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int filas = 0;
  int columnas = 0;
  int dias = 0;

  // lectura de valores
  cin>>filas>>columnas>>dias;

  // lectura de matriz
  matriz oceano = matriz(filas, vector<char> (columnas, '.'));
  for (int i=0; i<filas; i++) {
    for (int j=0; j<columnas; j++) {
      cin>>oceano[i][j];
    }
  }

  // PROCESAMIENTO
  // buscar la estacion de petroleo.
  for (int i=0; i<filas; i++) {
    for (int j=0; j<columnas; j++) {
      if (oceano[i][j] == '$') {
        realizarBusquedaIterativa(i,j,dias,oceano);
        break;
      }
    }
  }

  // imprimir matriz
  for (int i=0; i<filas; i++) {
    for (int j=0; j<columnas; j++) {
      cout<<oceano[i][j];
    }
    cout<<"\n";
  }

  return 0;
}