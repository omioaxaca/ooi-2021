/*
  https://omegaup.com/arena/problem/L-OMI-Super-Agente/#problems
  
  Solucion:
  Utilizar BFS para simular el movimiento de todos los guardias al mismo tiempo.
  En una matriz auxiliar, guardar la cantidad de pasos que necesita un guardia
  para llegar alli. Dado que se utiliza BFS, se garantiza que la primera vez que se
  visita una celda representa la menor cantidad de pasos necesarios que necesita
  dar el guardia mas cercano.
  Al final, se puede recorrer la matriz auxiliar para verificar cual es la cantidad
  de pasos mayor.
  
  Nota: Es importante que la BFS se haga al mismo tiempo para cada uno de los guardias,
        de esta forma el algoritmo es mas eficiente.
*/

#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int> > Matriz;

vector<int> fils = { -1, 0, 1, 0 };
vector<int> cols = { 0, 1, 0, -1 };

struct nodo {
  int x;
  int y;
  int distancia;
};

void bfs(queue<nodo> &cola, Matriz &matriz) {
  while(!cola.empty()) {
    nodo actual = cola.front();
    cola.pop();

    // procesamiento del nodo
    matriz[actual.x][actual.y] = actual.distancia;

    // visitar los vecinos 
    for(int k = 0; k < 4; k++){
      int nuevaX = actual.x + fils[k];
      int nuevaY = actual.y + cols[k];

      // si estamos adentro de la matriz
      if (nuevaX >= 0 && nuevaX < matriz.size() && nuevaY >= 0 && nuevaY < matriz[nuevaX].size()) {
        
        // si no hemos visitado ese vecino
        if (matriz[nuevaX][nuevaY] == 0) {
          // insertar en la cola.
          nodo vecino;
          vecino.x = nuevaX;
          vecino.y = nuevaY;
          vecino.distancia = actual.distancia + 1;
          cola.push(vecino);

          // marcar como visitado
          matriz[nuevaX][nuevaY] = -3;
        }
      }
    }
  }
}

void detonarBFS(vector<nodo> &guardias, Matriz &matriz){
  queue<nodo> cola;
  for(int i = 0; i < guardias.size(); i++){
    cola.push(guardias[i]);
  }
  bfs(cola, matriz);
}

int main() {

  int filas = 0;
  int columnas = 0;
  cin >> filas >> columnas; 

  // lectura de datos
  Matriz matriz(filas, vector<int>(columnas, 0));

  for (int i = 0; i < filas; i++) {
    for (int j = 0; j < columnas; j++) {
      char valor;
      cin>>valor;
      if (valor == 'G') {
        matriz[i][j] = -1;
      } else if (valor == '#') {
        matriz[i][j] = -2;
      }
    }
  }

  // procesamiento
  vector<nodo> guardias;
  for (int i = 0; i < filas; i++) {
    for (int j = 0; j < columnas; j++) {
      if (matriz[i][j] == -1) {
        nodo guardia;
        guardia.x = i;
        guardia.y = j;
        guardia.distancia = 0;
        guardias.push_back(guardia);
      }
    }
  }

  detonarBFS(guardias, matriz);

  // respuesta
  int maxPasos = 0;
  for (int i = 0; i < filas; i++) {
    for (int j = 0; j < columnas; j++) {
      maxPasos = max(maxPasos, matriz[i][j]);
    }
  }

  cout << maxPasos << endl;

  return 0;
}