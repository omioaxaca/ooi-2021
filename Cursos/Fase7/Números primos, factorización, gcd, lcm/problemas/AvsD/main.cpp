/*
    https://omegaup.com/arena/problem/Abigael-vs-Daniel/#problems

    Referencias:
        https://en.wikipedia.org/wiki/Pollard%27s_rho_algorithm
        https://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test

    @autor Esaú Peralta
	@email: esau.opr@gmail.com
*/

#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm> // __gcd()
#include <map>
using namespace std;

#define u64 long long
#define dbl long double

#define MAX 1000010

vector<u64> primes;
bitset<MAX> sieve;

void fill_sieve() {
    sieve.set();
    sieve.reset(0); sieve.reset(1);
    for( int i = 2; i < MAX; i++ ) {
        if( sieve[ i ] ) {
            primes.push_back( i );
            for( int j = i*2; j < MAX; j+=i ) {
                sieve.reset(j);
            }
        }
    }
}

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

bool ispmiller(u64 p) { // O(30*logp)
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

inline u64 pollardrho(u64 n) { // O(n^0.25)
	if(n==1) return 1;
	if(n%2==0) return 2;
	u64 c=myrand(n-1)+1, x=myrand(n-2)+2, y=x;
	u64 d=1; while(d==1) {
		x=mul(x,x,n)+c; if(x>=n) x-=n;
		y=mul(y,y,n)+c; if(y>=n) y-=n;
		y=mul(y,y,n)+c; if(y>=n) y-=n;
		d=__gcd(abs(x-y),n);
		if(d==n) return (ispmiller(n) ? n:pollardrho(n));
	}
	return d;
}

map<u64, int> get_factors(u64 num) {
    map<u64, int> factors;

    // Revisamos si es primo y evitamos buscar factores
    if(ispmiller(num)) {
    	factors[num] ++;
    	return factors;
    }

    // Buscamos los factores
    for(u64 i=0; i<primes.size() && primes[i]*primes[i] <= num; i++) {
    	if(num % primes[i]==0) {
    		while(num % primes[i] == 0) {
    			num /= primes[i];
    			factors[primes[i]]++;
    		}
    	}
    }

    // Revisamos si el residuo es primo
    if(ispmiller(num)) {
    	factors[num]++;
    } else if(num > 1) {
        // Como no es primo obtenemos un factor con el algoritmo de Pollard Rho
    	u64 x = pollardrho(num);
    	factors[x]++;
    	factors[num/x]; // El otro primo lo obtenemos dividiendo el residuo
    }

    return factors;
}


int main() {
    u64 num1, num2;

    cin >> num1 >> num2;

    // Los limites de la solución son hasta 10^18
    // Calcular la criba hasta 10^9 y luego obtener los factores es muy tardado
    // Podemos dividir el problema en 2 partes
    // 1. Calcular los factores hasta 10^6 lo que nos asegura que si existe un residuo al momento de
    //    fatorizar este estará en el rango de 10^6 a 10^18
    // 2. Solo puede haber lo mas dos primos en el rango de 10^6 a 10^18
    //    Ejemplo Si elegimos 3 números con el valor min de 10^6 y los multiplicamos tendremos 10^18
    //    Si existieran 3 primos P1, P2, y P3 mayores a 10^6 su multiplicación excede 10^18
    //    Por lo que solo pueden haber a lo mas dos.
    //
    //    Solo basta calcular si el residuo es un primo con el test de Miller–Rabin
    //    Si no es primo, obtenemos un factor primo con el algoritmo de Pollar Rho
    //    y el primo restante es la división del factor primo anterior con el residuo previo.

    fill_sieve();

    map<u64, int> factors1 = get_factors(num1);
    map<u64, int> factors2 = get_factors(num2);

    if (factors1.size() > factors2.size()) {
        cout << "Daniel" << endl;
    } else if(factors1.size() == factors2.size()) {
        cout << "Empate" << endl;
    } else {
        cout << "Abigael" << endl;
    }

    for (auto &fact: factors1) {
        cout << fact.first << " ";
    }
    cout << "\n";

    for (auto &fact: factors2) {
        cout << fact.first << " ";
    }
    cout << "\n";

    return 0;
}
