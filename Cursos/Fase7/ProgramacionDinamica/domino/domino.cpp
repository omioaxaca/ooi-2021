/*
  Link: https://omegaup.com/arena/problem/El-rectangulo-de-domino/
  Solucion: Programación Dinámica

  Ejecutar: g++ -std=c++11 domino.cpp -o domino && ./domino < domino.in > domino.out
*/

/*
  La programación dinamica es una técnica que permite resolver problemas de naturaleza recursiva. 
  Se aplica cuando el problema lo puedes dividir en problemas mas pequeños que se sobreponen, con la finalidad
  de minimizar el número de operaciones.

  La programación dinamica, comunmente es implementada con Tabulación (iterativa) (Bottom Up), pero tambien puede usarse
  con memorización (recursiva)(Top Down).

  Tabulación (Iterativa, Bottom Up): Resolver los subproblemas primero (bottom) y guardar los resultados en una tabla
  de dimensiones n, despues, basandose en los resultados, progresivamente ir resolviendo los demas subproblemas hasta llegar 
  al problema original (top).  

  Memorización (Recursiva, Top Down): Empezar a resolver el problema original (top) y despues recursivamente resolver
  los subproblemas (bottom) Ayudarse de una tabla para guardar los resultados ya procesados.
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/*
  Función recursiva de la forma TOP-DOWN
*/
ll calcularFormasRecursivo (int n, vector<ll> &dp) {
  // caso base: 
  if (n == 1) return 1;
  if (n == 2) return 2;

  // si ya hemos calculado la solución para esta n, devolvemos la solución.
  if (dp[n] != -1) return dp[n];

  // si no, calculamos la solución para el subproblema
  ll solucion = calcularFormasRecursivo(n-1, dp) + calcularFormasRecursivo(n-2, dp);
  
  // y la guardamos en la tabla
  dp[n] = solucion;

  // devolvemos la solución
  //cout<<"calcularFormas: n="<<n<<" -> "<<solucion<<endl;
  return solucion;  
}

ll calcularFormasIterativo(int n, vector<ll> &dp) {
  dp[1] = 1;
  dp[2] = 2;

  for (int i=3; i<=n; i++) {
    dp[i] = dp[i-1] + dp[i-2];
  }

  return dp[n];
}

int main() {
  int n;
  cin >> n;

  vector<ll> dp (n+4, -1);

  ll resultadoRecursivo = calcularFormasIterativo(n, dp);

  cout<< resultadoRecursivo << endl;

  return 0;
}