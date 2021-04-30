// 12249. El maestro Toño (Palabras).
// https://omegaup.com/arena/problem/El-maestro-Tono-Palabras/
// 

#include<bits/stdc++.h>

using namespace std;

int main() {

  string palabra = "";
  int contador = 0;
  while(cin>>palabra) { // Lee las palabras hasta que ya no encuentra mas.
    contador++;
    cout<<"P"<<contador<<" "<<palabra<<endl;
  }

  // OTRA FORMA DE HACERLO:

  /*
  // si el problema, tuviera otro delimitador que no fuera el espacio, tendríamos que leer toda la cadena
  // con getline para despues procesarla manualmente

  string cadena;
  getline(cin, cadena); // Leer junto con espacios hasta el salto de linea o EOF

  string tmp = "";
  int contador = 0;
  for (int i=0; i<cadena.size(); i++) {
    char caracter = cadena[i];
    if (caracter == ' ') {
      contador++;
      cout<<"P"<<contador<<" "<<tmp<<endl;
      tmp = "";
    } else {
      tmp = tmp + caracter;
    }
  }
  cout<<"P"<<contador+1<<" "<<tmp<<endl; // imprimir la ultima palabra que queda en tmp.
  */

  return 0;
}