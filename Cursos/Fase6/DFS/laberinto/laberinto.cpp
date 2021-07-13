/*
  https://omegaup.com/arena/problem/laberinto
*/

#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<char> > matriz;

/*
  compilar con la bandera de C++11 para que funcione la declaración de estos vectores.
  g++ -std=c++11 laberinto.cpp -o laberinto && ./laberinto < laberinto.in > laberinto.out
*/

vector<int> fils = { -1, 0, 1, 0 };
vector<int> cols = { 0, 1, 0, -1 };

void dfs(int i, int j, int vida, int multiplicadorVida, int &vidaMaxima, matriz &laberinto) {
  
  if (laberinto[i][j] == 'S') {
    // cout<<"SOLUTION: "<<i<<" , "<<j<<" - "<<vida<<endl;
    vidaMaxima = max(vida, vidaMaxima);
    return;
  }

  if (laberinto[i][j] != '#') {
    // Calcular la vida hasta el momento y ver si podemos seguir
    int vidaEnCasilla = 0;
    if (isdigit(laberinto[i][j])) {
      vidaEnCasilla = (int)laberinto[i][j] - '0';
    };
    int vidaRestante = (vida - 1) + (vidaEnCasilla * multiplicadorVida);

    if (vidaRestante <= 0) {
      return;
    };

    char guardarValor = laberinto[i][j];
    laberinto[i][j] = '#';
    
    for (int v=0; v<4; v++) {
      int nuevaI = i + fils[v]; 
      int nuevaJ = j + cols[v];

      if (nuevaI >= 0 && nuevaI < laberinto.size() && nuevaJ >= 0 && nuevaJ < laberinto[nuevaI].size()) {
        if (laberinto[nuevaI][nuevaJ] != '#') {
          dfs(nuevaI, nuevaJ, vidaRestante, multiplicadorVida, vidaMaxima, laberinto);
        }
      }
    }

    laberinto[i][j] = guardarValor;
  }
}

void realizarBusqueda(int i, int j, int vidaInicial, int multiplicadorVida, int &vidaMaxima, matriz &laberinto) {
  laberinto[i][j] = '#';
  for (int v=0; v<4; v++) {
    int nuevaI = i + fils[v]; 
    int nuevaJ = j + cols[v];

    if (nuevaI >= 0 && nuevaI < laberinto.size() && nuevaJ >= 0 && nuevaJ < laberinto[nuevaI].size()) {
      if (laberinto[nuevaI][nuevaJ] == '.') {
        dfs(nuevaI, nuevaJ, vidaInicial - 1, multiplicadorVida, vidaMaxima, laberinto);
      }
    }
  }
}

int main () {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int filas = 0;
  int columnas = 0;
  int vidaInicial = 0;
  int multiplicadorVida = 0;

  // lectura de valores
  cin>>filas>>columnas>>vidaInicial>>multiplicadorVida;

  // lectura de matriz
  matriz laberinto = matriz(filas, vector<char> (columnas, '.'));
  for (int i=0; i<filas; i++) {
    for (int j=0; j<columnas; j++) {
      cin>>laberinto[i][j];
    }
  }

  // PROCESAMIENTO
  int vidaMaxima = -1;
  for (int i=0; i<filas; i++) {
    for (int j=0; j<columnas; j++) {
      if (laberinto[i][j] == 'I') {
        realizarBusqueda(i, j, vidaInicial, multiplicadorVida, vidaMaxima, laberinto);
        break;
      }
    }
  }
  
  if (vidaMaxima > -1) {
    cout<<vidaMaxima<<endl;
  } else {
    cout<<"NOPE"<<endl;
  }

  return 0;
}