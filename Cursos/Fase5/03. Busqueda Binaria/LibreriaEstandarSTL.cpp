#include<bits/stdc++.h>

using namespace std;

int main () {
  int enteros[] = {10,20,30,30,20,10,10,20};
  vector<int> v(enteros,enteros+8);           // 10 20 30 30 20 10 10 20

  sort (v.begin(), v.end());                // 10 10 10 20 20 20 30 30

  vector<int>::iterator izq = lower_bound (v.begin(), v.end(), 30);
  vector<int>::iterator der = upper_bound (v.begin(), v.end(), 30);
  bool existe = binary_search(v.begin(), v.end(), 10);

  if (existe) {
    cout << "existe el numero" << '\n'; 
  } else {
    cout << "no existe"<< '\n';
  }

  cout << "lower_bound en la posicion " << (izq - v.begin()) << '\n'; 
  cout << "upper_bound en la posicion " << (der  - v.begin()) << '\n';

  return 0;
}