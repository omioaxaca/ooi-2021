/*
  SUDOKU - UVA - 989
  LINK: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=16&page=show_problem&problem=930

  SOLUCION: BACKTRACKING

  Ejecutar: g++ -std=c++11 sudoku.cpp -o sudoku && ./sudoku < sudoku.in > sudoku.out

  NOTA: El codigo resuelve correctamente cualquier sudoku de 9x9, falta agregarle unos detalles
  para las demas soluciones de 3x3 y 6x6 que es lo que pide el problema, asi como los multiples casos que vienen.
  ya que este programa solo resuelve un caso.

*/

#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int> > Matriz;

bool seRepiteEnColumna(Matriz &tablero, int columna, int num) {
  for (int i = 0; i < tablero.size(); i++) {
    if (tablero[i][columna] == num) {
      return true;
    }
  }
  return false;
}

bool seRepiteEnFila(Matriz &tablero, int fila, int num) {
  for (int j = 0; j < tablero[fila].size(); j++) {
    if (tablero[fila][j] == num) {
      return true;
    }
  }
  return false;
}

bool seRepiteEnCuadro(Matriz &tablero, int inicioFila, int inicioCol, int num) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (tablero[inicioFila + i][inicioCol + j] == num) {
        return true;
      }
    }
  }
  return false;
}

bool esUnLugarValido(Matriz &tablero, int i, int j, int num) {
  int inicioFila = i - i % 3;
  int inicioCol = j - j % 3;
  return !seRepiteEnFila(tablero, i, num) && !seRepiteEnColumna(tablero, j, num) && !seRepiteEnCuadro(tablero, inicioFila, inicioCol, num);
}

void imprimir(Matriz &tablero) {
  for (int i = 0; i < tablero.size(); i++) {
    for (int j = 0; j < tablero[i].size(); j++) {
      cout << tablero[i][j];
    }
    cout << endl;
  }
}

pair<int,int> siguienteLugarVacio(Matriz &tablero) {
  for (int i = 0; i < tablero.size(); i++) {
    for (int j = 0; j < tablero[i].size(); j++) {
      if (tablero[i][j] == 0) {
        return make_pair(i, j);
      }
    }
  }
  return make_pair(-1, -1);
}

/*
  Funcion recursiva que nos ayuda a evaluar todas las posibles soluciones para 
  las casillas que estan en cero en el tablero.
*/
bool resolver(Matriz &tablero, pair<int,int> casilla, int tamano) {

  // si la casilla en la que estamos es -1, -1, entonces se ha llegado a la solucion
  if (casilla.first == -1 && casilla.second == -1) {
    return true;
  }

  // Probamos todas las posibles soluciones de numeros que pueden ir de 1 al size.
  // recorremos los numeros del menor al mayor para asegurar que la primer solución que 
  // encontramos, sea la lexicograficamente menor. 
  for (int num = 1; num <= tamano; num++) {

    // comprobamos si la posible solucion es valida:
    if (esUnLugarValido(tablero, casilla.first, casilla.second, num)) {

      // si es valida, la guardamos en el tablero y continuamos buscando mas soluciones. 
      tablero[casilla.first][casilla.second] = num;

      // buscamos la siguiente casilla en la que se pueda poner un numero.
      // nos regresa un pair donde first = i, second = j y ambos en -1 quiere decir
      // que no hay una siguiente casilla en la que poner un numero.
      // esto es el equivalente cuando hacemos el +1 cuando bajamos por los niveles de la busqueda en otros problemas
      pair<int, int> siguienteCasillaVacia = siguienteLugarVacio(tablero);

      if (resolver(tablero, siguienteCasillaVacia, tamano)) {
        // si la funcion recursiva nos regresa true, quiere decir que a partir de este nodo hemos 
        // encontrado una solucion.
        return true;
      }
      // si no, la borramos del tablero y continuamos buscando mas soluciones.
      tablero[casilla.first][casilla.second] = 0;    
    }
  }
  
  return false;
}

int main() {
  int n;
  cin>>n;

  // los sudokus que vienen en el input son de 9x9 o 3x3 o 6x6 
  int tamano = n*n;
  Matriz tablero(tamano, vector<int>(tamano, 0));

  // lectura del tablero
  for (int i = 0; i < tamano; i++) {
    for (int j = 0; j < tamano; j++) {
      cin>>tablero[i][j];
    }
  }

  // Procesamiento
  pair<int, int> primerCasillaVacia = siguienteLugarVacio(tablero);
  bool tieneSolucion = resolver(tablero, primerCasillaVacia, tamano);

  // impresion de respuesta
  if (tieneSolucion) {
    imprimir(tablero);
  } else {
    cout<<"NO SOLUTION"<<endl;
  }
}