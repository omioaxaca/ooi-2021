/*
  https://omegaup.com/arena/problem/Escape-del-laberinto/
  
  Solucion: BACKTRACKING, DFS, BFS

  g++ -std=c++11 laberinto.cpp -o laberinto && ./laberinto < laberinto.in > laberinto.out
*/

#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<char> > Matriz;

vector<int> fils = { -1, 0, 1, 0 };
vector<int> cols = { 0, 1, 0, -1 };

/*
  Busqueda recursiva que devuelve si encontró salida o no en a partir de ese nodo.
*/
bool busqueda(Matriz &laberinto, int i, int j, Matriz &solucion) {
  
  char posActual = laberinto[i][j];

  if (posActual == 'S') {
    return true;
  }

  for (int k = 0; k < 4; k++) {
    int nx = i + fils[k];
    int ny = j + cols[k];
    bool noSaleMatriz = (nx >= 0 && nx < laberinto.size() && ny >= 0 && ny < laberinto[nx].size());

    if (noSaleMatriz && laberinto[nx][ny] != '#' && solucion[nx][ny] == ' ') {
      solucion[nx][ny] = '#';
      if (busqueda(laberinto, nx, ny, solucion)) {
        return true;
      }
      // solucion[nx][ny] = ' ';   // Removemos el backtacking para que no se repitan las soluciones
    }
  }

  return false;
}

int main() {
  int filas, columnas;
  // Lectura de datos
  cin>>filas>>columnas;
  cin.ignore();

  Matriz laberinto = Matriz(filas, vector<char>(columnas, ' '));
  Matriz solucion = Matriz(filas, vector<char>(columnas, ' '));
  
  for (int i=0; i<filas; i++) {
    string s;
    getline(cin,s);
    for (int j=0; j<s.size(); j++) {
      laberinto[i][j] = s[j];
    }
  }

  // Procesamiento
  bool tieneSalida = false;
  for (int i=0; i<filas; i++) {
    for (int j=0; j<columnas; j++) {
      if (laberinto[i][j] == 'E') {
        solucion[i][j] = '#';
        tieneSalida = busqueda(laberinto, i, j, solucion);
        break;
      }
    }
  }

  // Imprimir la salida
  if (tieneSalida) {
    cout<<"Si"<<endl;
  } else {
    cout<<"No"<<endl;
  }

  return 0;
}