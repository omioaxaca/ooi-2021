#include <iostream>
#include <stack>
#include <ctype.h>

using namespace std;

int evaluador(int val1, int val2, char c) {
  int value = 0;
  switch(c) {
    case '+':
      value = val1 + val2;
      break;
    case '-':
      value = val1 - val2;
      break;
    case '*':
      value = val1 * val2;
      break;
    case '/':
      value = val1 / val2;
      break;
  }
  cout << " operador " << c <<  endl;
  cout << " val1 = " << val1 <<  endl;
  cout << " val2 = " << val2 <<  endl;
  return value;
}


int main(){
  string cadena;
  cin >> cadena;
  stack<int> pila;

  // cout << "es digito ? " <<isdigit(cadena[0])<< endl;
  // cout << "es digito ?" <<isdigit('9') << endl;
  //cout << "valor int " << (int)'9' << endl;
  for(int i = 0; i < cadena.size() ; i++){
    char actual = cadena[i];
    if(isdigit(actual)){
      int valorInt = (int)actual - 48;
      pila.push(valorInt);
    }else{
      int val2 = pila.top();
      pila.pop();
      int val1 = pila.top();
      pila.pop();
      int valor = evaluador(val1, val2, actual);
      pila.push(valor);
    }
  }

  cout << " resultado de operacion :" << pila.top() << endl;
}

 //23+31++ expresion correcta 
 // (2 + 3) + (3 + 1)

 //16*21/34-+
 // (1 * 6) aqui nos falta un operador (2 / 1) + (3-4) incorrecta por que no tenemos com evaluar el ultimo resultado

 //12*42/34+5*-+
// (1 * 2) + (4 / 2) - ((3 + 4) * 5) expresion correcta
