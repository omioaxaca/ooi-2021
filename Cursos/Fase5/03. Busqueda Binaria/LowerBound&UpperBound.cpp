#include <bits/stdc++.h>

using namespace std;

int custom_lower_bound(vector<int>& arreglo, int x) {
    int ini = 0;
    int fin = arreglo.size();
 
    // mientras el inicio sea menor que el fin
    while (ini < fin) {
        int mid = ini + (fin - ini) / 2; // calculamos el punto medio entre ini y fin
 
        // si X es menor o igual que el valor de enmedio
        // nos vamos a ir a la izquierda.
        if (x <= arreglo[mid]) {
          fin = mid;
        } else { // en caso contrario nos tenemos que ir a la derecha
          ini = mid + 1;
        }
    }
    // terminamos el ciclo y tenemos que verificar
    // si X es mayor que el ultimo valor del arreglo
    if(ini < arreglo.size() && arreglo[ini] < x) {
      ini++;
    }
       
    // regresamos ini, quien tiene la respuesta del indice de lower_bound;
    return ini;
}
 
int custom_upper_bound(vector<int>& arreglo, int x) {
    int ini = 0;
    int fin = arreglo.size();
 
    // mientras el inicio sea menor que el fin
    while (ini < fin) {
        int mid = ini + (fin - ini) / 2; // calculamos el punto medio entre ini y fin

        // si X es mayor o igual que el valor de enmedio
        // nos vamos a ir a la derecha.
        if (x >= arreglo[mid]) {
          ini = mid + 1;
        } else { // en caso contrario nos tenemos que ir a la izquierda.
          fin = mid;
        }
    }
   
    // terminamos el ciclo y tenemos que verificar
    // si X es mayor que el ultimo valor del arreglo
    // con la finalidad de indicar que la respuesta se encuentra fuera.
    if(ini < arreglo.size() && arreglo[ini] < x) {
      ini++;
    }
       
    // regresamos ini, quien tiene la respuesta del indice de lower_bound;
    return ini;
}


int main() {
  vector<int> arreglo;

  for (int i=0; i<20; i++) {
    arreglo.push_back(i);
    arreglo.push_back(i);
    arreglo.push_back(i);
  }

  int buscar = 50;
  int lower_indice = custom_lower_bound(arreglo, buscar);
  int upper_indice = custom_upper_bound(arreglo, buscar);

  cout<<"Hemos encontrado el numero en el arreglo, en el indice:"<<endl;
  cout<<"LOWER BOUND: "<<lower_indice<<"  VAL: "<<arreglo[lower_indice]<<endl;
  cout<<"UPPER BOUND: "<<upper_indice<<"  VAL: "<<arreglo[upper_indice]<<endl;
}