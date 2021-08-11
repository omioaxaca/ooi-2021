/*
 	Problema: https://omegaup.com/arena/problem/Juanito-y-los-primos/

	Referencias:
	https://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test
	https://home.sandiego.edu/~dhoffoss/teaching/cryptography/10-Rabin-Miller.pdf

	@autor Esaú Peralta
	@email: esau.opr@gmail.com
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define u64 long long
typedef long double dbl;

inline u64 mul(u64 a, u64 b, u64 m) {
	a%=m; if(a<0) a+=m;
	b%=m; if(b<0) b+=m;
	u64 q = ((dbl)a * (dbl)b) / (dbl)m;
	u64 r = a*b - q*m;
	return (r<0 ? r+m:r);
}

inline u64 pwr(u64 a, u64 n, u64 m) {
    u64 ans(1);
    while(n) {
        if(n & 1) ans = mul(ans, a, m);
        if(n >>= 1) a = mul(a, a, m);
    }
    return ans%m;
}

u64 myrand(u64 n) {
	return rand()%n*rand()%n*rand()%n;
}

bool ispmiller(u64 p) {
	if(p<2) return false;
	if(p==2) return true;
	if(p%2==0) return false;
	u64 s=p-1; s>>=__builtin_ctzll(s);
	for(u64 i=0; i<60; i++) {
		u64 val=pwr(myrand(p-1)+1,s,p), temp=s;
		while(temp!=p-1 and 1<val and val<p-1) {
			val=mul(val,val,p);
			temp<<=1;
		}
		if(val!=p-1 and temp%2==0) return false;
	}
	return true;
}

int main() {
    u64 n; cin >> n;
	// El rango es hasta 10^18 calcular la criba hasta 10^9 y luego buscar si puede ser dividido
	// por alguno de los factores es tardado

	// Usamos la prueba: Miller–Rabin primality test
	// para saber si un número es primo o no

    if(ispmiller(n)) {
    	cout << "si es primo\n";
    } else {
        cout << "no es primo\n";
    }

    return 0;
}
