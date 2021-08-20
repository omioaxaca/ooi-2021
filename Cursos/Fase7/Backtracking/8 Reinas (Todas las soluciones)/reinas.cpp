/*
  Link: https://cses.fi/problemset/task/1624/
  Solucion: Backtracking
  probar todas las posibles posiciones para cada reina y conforma vayamos encontrando una 
  vamos añadiendo las posiciones a una lista y luego las vamos añadiendo a la solucion
  y si no hay solucion se regresa un paso hacia atras.

  Optimizacion:
  - Buscar una reina por cada fila del tablero.

  
  Ejecutar: g++ -std=c++11 reinas.cpp -o reinas && ./reinas < reinas.in > reinas.out
*/

#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int> > Matriz;

struct coord {
  int x;
  int y;
};

bool validarTablero(vector<coord> &reinas, coord &nuevaReina) {
  // Comprobamos que las reinas no se solapen, comparando la ultima reina que queremos agregar
  // con todas las que ya tenemos en el arreglo.
  // a.x == b.x  ambas no esten en la misma fila
  // a.y == b.y  ambas no esten en la misma columna
  // (abs(a.x - b.x) == abs(a.y - b.y))  ambas no esten en la misma diagonal

  // Checa la ultima reina contra todas las anteriores.
  for (int i=0; i<reinas.size(); i++) {
    if (reinas[i].x == nuevaReina.x || reinas[i].y == nuevaReina.y || (abs(reinas[i].x - nuevaReina.x) == abs(reinas[i].y - nuevaReina.y))) {
      return false;
    }
  }
  // el tablero esta en armonia
  return true;
}

// Funcion recursiva que busca la solucion de las reinas. y retorna las soluciones encontradas
// a partir de ese nodo.
int busqueda(int filaActual, Matriz &ocupado, vector<coord> &solucion) {

  // si estamos en la fila 8, quiere decir que ya encontramos 8 reinas.
  if (filaActual == 8) { // hemos encontrado las reinas restantes.
    return 1;
  }

  int soluciones = 0;
  // Generar los vecinos de busqueda del nodo, o el siguiente espacio de busqueda
  // recorrer las columnas en la fila actual.
  for (int j=0; j<8; j++) {
    coord nuevaReina = {filaActual, j};
    if (ocupado[filaActual][j] == 0 && validarTablero(solucion, nuevaReina)) { // si el espacio esta libre y es una solución.
      // agregar al candidato a la solución.
      solucion.push_back(nuevaReina);
      // recursivamente seguir buscando mas reinas.
      soluciones += busqueda(filaActual+1, ocupado, solucion);
      // Quitar la ultima reina de la solución.
      solucion.pop_back();
    }
  }

  return soluciones;
}

int main() {

  // lecutura de casillas que estan bloqueadas.
  Matriz ocupado = Matriz(8, vector<int>(8, 0));
  for (int i=0; i<8; i++) {
    for (int j=0; j<8; j++) {
      char casilla;
      cin>>casilla;
      if (casilla == '*') {
        ocupado[i][j] = 1;
      }
    }
  }

  // EJECUCION:
  // Buscar 8 reinas.
  vector<coord> solucion;
  int soluciones = busqueda(0, ocupado, solucion);

  // IMPRIMIR RESULTADO:
  cout<<soluciones<<endl;
}
