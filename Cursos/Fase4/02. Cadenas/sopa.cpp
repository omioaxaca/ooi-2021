// 12524. Sopa de consonantes, vocales y numeros
// https://omegaup.com/arena/problem/Sopa-consonantes-vocales-y-num/#problems
// 

#include <bits/stdc++.h>

using namespace std;

int main() {

  string text = "";
  int consonantes = 0;
  int vocales = 0;
  int numeros = 0;

  int parrafos = 0;
  cin>>parrafos;
  cin.ignore(); // agregarlo despues de leer con cin y querer usar getline despues.

  // leemos todo el texto y lo guardamos en la variable string text.
  for (int i=0; i<parrafos; i++) {
    string tmp = "";
    getline(cin, tmp);
    text += tmp;
  }

  // iteramos el texto y procesamos caracter por caracter para ver que tipo son:
  for (int i=0; i<text.size(); i++) { 
    char caracter = text[i];
    if (isdigit(caracter)) { // si es digito aumentamos el contador
      numeros++;
    } else if ((tolower(caracter) == 'a' || tolower(caracter) == 'e' || tolower(caracter) == 'i' || tolower(caracter) == 'o' || tolower(caracter) == 'u')) {
      vocales++;
    } else if (isalpha(caracter)) { // si es un caracter alfanumerico, (quita los signos de punctuación)
      consonantes++;
    }
  }

  cout<<consonantes<<" "<<vocales<<" "<<numeros<<endl;

  return 0;
}