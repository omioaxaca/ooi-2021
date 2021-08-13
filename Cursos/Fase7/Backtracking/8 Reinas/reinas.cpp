/*
  Link: https://omegaup.com/arena/problem/8Reinas/
  Solucion: Backtracking
  probar todas las posibles posiciones para cada reina y conforma vayamos encontrando una 
  vamos añadiendo las posiciones a una lista y luego las vamos añadiendo a la solucion
  y si no hay solucion se regresa un paso hacia atras.

  Ejecutar: g++ -std=c++11 reinas.cpp -o reinas && ./reinas < reinas.in > reinas.out
*/

#include <bits/stdc++.h>

using namespace std;

struct coord {
  int x;
  int y;
};

bool validarTablero(vector<coord> &reinas) {
  // Comprobamos que las reinas no se solapen, comparando todas las combinaciones de reinas 
  // formando par de reinas, y por cada par comprobamos que:
  // a.x == b.x  ambas no esten en la misma fila
  // a.y == b.y  ambas no esten en la misma columna
  // (abs(a.x - b.x) == abs(a.y - b.y))  ambas no esten en la misma diagonal
  for (int i=0; i<reinas.size(); i++) {
    for (int j=i+1; j<reinas.size(); j++) {
      coord reinaA = reinas[i];
      coord reinaB = reinas[j];
      if (reinaA.x == reinaB.x || reinaA.y == reinaB.y || (abs(reinaA.x - reinaB.x) == abs(reinaA.y - reinaB.y))) {
        return false;
      }
    }
  }
  // el tablero esta en armonia
  return true;
}

// Funcion recursiva que busca la solucion de las reinas.
void busqueda(int reinaActual, int reinasABuscar, vector<coord> &reinas, vector<coord> &solucion) {
  
  // si ya tenemos una solución ya no es necesario seguir buscando.
  if (solucion.size() > 0) return;

  // si la reina que debemos de buscar es la novena, quiere decir que ya encontramos 8 anteriores.
  if (reinaActual > reinasABuscar) { // hemos encontrado las reinas restantes.
    // guardamos la solución en otro vector para que al momento que la función revursiva regrese,
    // no afecte nuestra solución que tenemos en el arreglo de reinas.
    solucion = reinas;
    return;
  }

  // Generar los vecinos de busqueda del nodo, o el siguiente espacio de busqueda.
  for (int i=1; i<=8; i++) {
    for (int j=1; j<=8; j++) {
      // nuevo candidato de solucion.
      coord nuevaReina = {i, j};
      // agregar al candidato a la solución.
      reinas.push_back(nuevaReina);

      // validar que sigamos teniendo una solución general.
      if (validarTablero(reinas)) {
        busqueda(reinaActual+1, reinasABuscar, reinas, solucion);
      }
      
      // Quitar la ultima reina de la solución.
      reinas.pop_back();
    }
  }

  return;
}

int main() {
  vector<coord> reinas;
  int numReinas = 0;

  // LECTURA DE DATOS:
  cin>> numReinas;
  for(int i = 0; i < numReinas; i++) {
    int x, y;
    cin>>x>>y;
    coord c = {x, y};
    reinas.push_back(c);
  }

  // EJECUCION:
  // Buscar las siguientes 8 - numReinas
  int reinasABuscar = 8 - numReinas;
  vector<coord> solucion;
  busqueda(1, reinasABuscar, reinas, solucion);

  // IMPRIMIR RESULTADO:
  if (solucion.size() > 0) {
    for (int i=0; i<solucion.size(); i++) {
      cout<<solucion[i].x<<" "<<solucion[i].y<<endl;
    }
  } else {
    cout<<0<<endl;
  }

}
