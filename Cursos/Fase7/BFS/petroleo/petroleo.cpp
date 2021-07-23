/*
  https://omegaup.com/arena/problem/COMI-Derrame-de-Petroleo/
  
  Solucion:
  Utilizar BFS para simular el movimiento del petroleo sobre el oceano. Correr la BFS mientras el nivel
  del BFS sea menor a los días que tenemos que hacer la simulación.
*/

#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<char> > Matriz;

vector<int> fils = { -1, 0, 1, 0 };
vector<int> cols = { 0, 1, 0, -1 };

struct nodo {
  int x;
  int y;
  int dias;
};

void realizarBusquedaEnAmplitud(Matriz &oceano, int i, int j, int dias) {
  // inicialiar nuestra cola;
  queue<nodo> cola;

  nodo inicial;
  inicial.x = i;
  inicial.y = j;
  inicial.dias = 1;

  cola.push(inicial);

  // marcar como visitado el nodo actual.
  oceano[i][j] = '$';

  // mientras la cola no esté vacía
  while (!cola.empty()) {
    // extraer el nodo de la cola
    nodo actual = cola.front();
    cola.pop();

    // procesamiento del nodo actual
    if (actual.dias > dias) {
      continue;
    }

    // recorrer los vecinos del nodo actual
    for (int k = 0; k < 4; k++) {
      int nuevaI = actual.x + fils[k];
      int nuevaJ = actual.y + cols[k];

      // si estamos adentro de la matriz
      if (nuevaI >= 0 && nuevaI < oceano.size() && nuevaJ >= 0 && nuevaJ < oceano[nuevaI].size()) {
        // si el nodo no fue visitado (osea es agua)
        if (oceano[nuevaI][nuevaJ] == '.') {
          // agregarlo a la cola
          nodo vecino;
          vecino.x = nuevaI;
          vecino.y = nuevaJ;
          vecino.dias = actual.dias + 1;
          cola.push(vecino);
          // marcarlo como visitado
          oceano[nuevaI][nuevaJ] = '*';
        }
      }
    
    }
  }

}

int main() {
  int filas, columnas;
  int dias;

  // Lectura de datos
  cin>>filas>>columnas>>dias;

  Matriz oceano = Matriz(filas, vector<char>(columnas, '.'));
  for (int i=0; i<filas; i++) {
    for (int j=0; j<columnas; j++) {
      cin>>oceano[i][j];
    }
  }

  // Procesamiento
  for (int i=0; i<filas; i++) {
    for (int j=0; j<columnas; j++) {
      if (oceano[i][j] == '$') {
        realizarBusquedaEnAmplitud(oceano, i, j, dias);
        break;
      }
    }
  }

  // Imprimir la salida
  for (int i=0; i<filas; i++) {
    for (int j=0; j<columnas; j++) {
      cout<<oceano[i][j];
    }
    cout<<endl;
  }
  return 0;
}