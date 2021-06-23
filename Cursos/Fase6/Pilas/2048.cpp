#include <iostream>
#include <stack>

using namespace std;
int main() {
    int primero, cant, count = 1 , num, sum = 0; 
    stack<int> pila;
    cin>>cant;
    cin >> primero;
    pila.push(primero);
    while( count < cant){
      cin >> num;
      int auxTop = pila.top();
      int sum = 0;
      if( auxTop == num){
        sum = num + auxTop;
        pila.pop();
        while(!pila.empty()){
          if(pila.top() == sum){
            sum += pila.top();
            pila.pop();
          }else {
            break;
          }
        }
        pila.push(sum);
      }else {
        pila.push(num);
      }
      count++;
    }

    cout << pila.size() << endl;
    while(!pila.empty()){
      cout << pila.top() << endl;
      pila.pop();
    }

}