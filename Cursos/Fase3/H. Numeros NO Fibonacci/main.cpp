#include <bits/stdc++.h>

using namespace std;

int main () {
  int a;
  cin >> a;
  int anteriorNum = 2;
  int nuevoNum = 3;
  int fibo = 0;

  while(fibo < a){
    fibo = anteriorNum + nuevoNum;
    anteriorNum = nuevoNum;
    nuevoNum = fibo;
    for(int i = anteriorNum + 1 ; i < nuevoNum ; i++){
        if( i < a ){
          cout << i << " ";
        }
      }
  }
  return 0;

}