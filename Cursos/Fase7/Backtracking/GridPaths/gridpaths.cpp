/*
  Link: https://cses.fi/problemset/task/1624/
  Solucion: Backtracking

  Optimizaciones:
  - Si hemos llegado al final y no pasamos por las 49 casillas, quiere decir que no es una solucion.
  
  Ejecutar: g++ -std=c++11 gridpaths.cpp -o gridpaths && ./gridpaths < gridpaths.in > gridpaths.out
*/

#include <bits/stdc++.h>

#define ARRIBA 0
#define DERECHA 1
#define ABAJO 2
#define IZQUIERDA 3
#define VISITADO 1
#define NO_VISITADO 0

using namespace std;

typedef vector<vector<int> > Matriz;

vector<int> fils = { -1, 0, 1, 0 };
vector<int> cols = { 0, 1, 0, -1 };

vector<int> esqFils = { -1, 1, 1, -1 };
vector<int> esqCols = { 1, 1, -1, -1 };

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

bool seDivideEnDosAreas(int i, int j, Matriz &visitados) {
  // inicializamos todos los cuadros alrededor como visitados.
  // esto con la finalidad de tambien abarcar las casillas que no estan en el grid.
  vector<int> visitadosAlrededor (4, 1);
  for (int k = 0; k < 4; k++) {
    int nx = i + fils[k];
    int ny = j + cols[k];
    if (adentroDeMatrix(nx, ny)) {
      visitadosAlrededor[k] = visitados[nx][ny];
    }
  }

  // ARRIBA ABAJO LIBRES / IZQUIERDA DERECHA OCUPADOS
  if (visitadosAlrededor[ARRIBA] == 0 && visitadosAlrededor[ABAJO] == 0 && visitadosAlrededor[DERECHA] == 1 && visitadosAlrededor[IZQUIERDA] == 1) {
    return true;
  }
  // ARRIBA ABAJO OCUPADOS / IZQUIERDA DERECHA LIBRES
  if (visitadosAlrededor[ARRIBA] == 1 && visitadosAlrededor[ABAJO] == 1 && visitadosAlrededor[DERECHA] == 0 && visitadosAlrededor[IZQUIERDA] == 0) {
    return true;
  }

  /* Indice - Movimiento
  0 - Arriba
  1 - Derecha
  2 - Abajo
  3 - Izquierda
  */
 
  // ESQUINAS
  for (int k = 0; k < 4; k++) {
    int nx = i + esqFils[k];
    int ny = j + esqCols[k];

    if (adentroDeMatrix(nx, ny) && visitados[nx][ny] == 1) {
      if (k == 0 && visitadosAlrededor[ARRIBA] == 0 && visitadosAlrededor[DERECHA] == 0) {
        return true;
      }
      if (k == 1 && visitadosAlrededor[DERECHA] == 0 && visitadosAlrededor[ABAJO] == 0) {
        return true;
      }
      if (k == 2 && visitadosAlrededor[IZQUIERDA] == 0 && visitadosAlrededor[ABAJO] == 0) {
        return true;
      }
      if (k == 3 && visitadosAlrededor[IZQUIERDA] == 0 && visitadosAlrededor[ARRIBA] == 0) {
        return true;
      }
    }
  }
  
  return false;
}

int buscaCaminos (int numeroCasilla, int i, int j, Matriz &visitados, string &secuencia) {

  //cout<<"buscaCaminos: "<<numeroCasilla<<" "<<i<<" "<<j<<endl;

  if (numeroCasilla == 48 && casillaFinal(i,j)) {
    return 1;
  } else if (numeroCasilla == 48 && !casillaFinal(i,j)) {
    return 0;
  } else if (seDivideEnDosAreas(i, j, visitados)) {
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