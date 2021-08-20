/*
  Link: https://cses.fi/problemset/task/1624/
  Solucion: Backtracking (Sin optimizar)
  
  Ejecutar: g++ -std=c++11 gridpaths.cpp -o gridpaths && ./gridpaths < gridpaths.in > gridpaths.out
*/

#include <bits/stdc++.h>
#define ARRIBA 0
#define DERECHA 1
#define ABAJO 2
#define IZQUIERDA 3

using namespace std;

typedef vector<vector<int> > Matriz;

vector<int> fils = { -1, 0, 1, 0 };
vector<int> cols = { 0, 1, 0, -1 };

bool adentroDeMatrix(int i, int j) {
  return i >= 0 && i < 7 && j >= 0 && j < 7;
}

bool puedoHacerMovimiento(int numeroCasilla, string& secuencia, int direccionActual) {
  char dirEnSecuencia = secuencia[numeroCasilla];
  if (dirEnSecuencia == '?') return true;

  if (direccionActual == ARRIBA && dirEnSecuencia == 'U') return true;
  if (direccionActual == DERECHA && dirEnSecuencia == 'R') return true;
  if (direccionActual == ABAJO && dirEnSecuencia == 'D') return true;
  if (direccionActual == IZQUIERDA && dirEnSecuencia == 'L') return true;

  return false;
}

bool casillaFinal(int i, int j) {
  return i == 6 && j == 0;
}

int buscaCaminos (int numeroCasilla, int i, int j, Matriz &visitados, string &secuencia) {

  //cout<<"buscaCaminos: "<<numeroCasilla<<" "<<i<<" "<<j<<endl;

  if (numeroCasilla == 48 && casillaFinal(i,j)) {
    return 1;
  } else if (numeroCasilla == 48 && !casillaFinal(i,j)) {
    return 0;
  }

  int soluciones = 0;

  for (int k = 0; k < 4; k++) {
    int nx = i + fils[k];
    int ny = j + cols[k];

    if (adentroDeMatrix(nx, ny) && visitados[nx][ny] == 0 && puedoHacerMovimiento(numeroCasilla, secuencia, k)) {
      visitados[nx][ny] = 1;
      soluciones += buscaCaminos(numeroCasilla + 1, nx, ny, visitados, secuencia);
      visitados[nx][ny] = 0;
    }
  }

  return soluciones;
}

int main () {
  string secuencia;
  cin>> secuencia;

  Matriz visitados(8, vector<int>(8, 0));

  visitados[0][0] = 1;
  int soluciones = buscaCaminos(0,0,0,visitados,secuencia);

  cout<<soluciones<<endl;
}