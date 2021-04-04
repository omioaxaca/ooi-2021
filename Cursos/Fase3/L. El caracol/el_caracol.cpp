#include <iostream>

using namespace std;

int main() {
  int profundidad, sube, resbala, metrosSubidos;
  cin >> profundidad >> sube >> resbala;
  int dias = 0;

  while(metrosSubidos < profundidad) {
    dias++;
    metrosSubidos += sube;
    if (metrosSubidos < profundidad) {
      metrosSubidos -= resbala;
    }
  }

  cout << dias;
}
