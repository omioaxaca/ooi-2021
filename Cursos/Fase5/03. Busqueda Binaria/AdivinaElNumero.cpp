// Adivina el numero
// https://omegaup.com/arena/problem/COMI-Adivina-el-numero#problems
// Busqueda binaria.


#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

long long pista(long long x);

void adivina(long long a, long long b) {
	ll ini = a;
	ll fin = b;

	while(ini <= fin) {

		ll mitad = ini + (fin - ini) / 2;
		ll pistaJuez = pista(mitad);
		if (pistaJuez == 0) {
			break;
		}
		if (pistaJuez == 1) {
			ini = mitad + 1;
		} else if (pistaJuez == -1) {
			fin = mitad - 1;
		}

	}

}