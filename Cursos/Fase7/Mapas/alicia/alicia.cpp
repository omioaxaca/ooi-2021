#include <bits/stdc++.h>

using namespace std;

int main() {
  int numPuertas;
  int numLlaves;

  // lectura
  cin>>numPuertas;
  vector<int> puertas (numPuertas);
  for(int i=0; i<numPuertas; i++) {
    cin>>puertas[i];
  }
  
  cin>>numLlaves;
  vector<int> llaves (numLlaves);
  for(int i=0; i<numLlaves; i++) {
    cin>>llaves[i];
  }

  // procesamiento

  // guardar el tamaño de las puertas en el mapa.
  map<int,int> mapaDePuertas;
  for(int i=0; i<numPuertas; i++) {
    mapaDePuertas[puertas[i]] = i+1;
  }

  for (int i=0; i<numLlaves; i++) {
    int llave = llaves[i];

    if (mapaDePuertas.find(llave) != mapaDePuertas.end()) {
      cout<<mapaDePuertas[llave]<<" ";
    } else {
      cout<<"0 ";
    }
  }

  return 0;
}


