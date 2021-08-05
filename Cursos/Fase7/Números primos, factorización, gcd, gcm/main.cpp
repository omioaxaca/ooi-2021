#include <iostream>
#include <cstdio>
#include <vector>
#include <bitset>

#define MAX 47000
using namespace std;

int gcd(int a, int b) {
	// Algoritmo de Euclides
	// https://www.khanacademy.org/computing/computer-science/cryptography/modarithmetic/a/the-euclidean-algorithm
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

void fill_sieve(vector<int> &primes) {
	// Criba de Eratóstenes
	// https://es.wikipedia.org/wiki/Criba_de_Erat%C3%B3stenes
	bitset<MAX> sieve; // También puedes usar un vector de boleanos

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

void get_prime_factors(int number, vector<int> &primes) {
	// El for solo va hasta la raiz de N, puesto que a lo más puede existir
	// un número primo mayor a su raíz.
	// Si existe será el último valor residual puesto que ya dividimos por todos los primos anteriores
    for (int i = 0; i < primes.size() && primes[i] * primes[i] <= number; i++) {
        while (number % primes[i] == 0) {
            number /= primes[i];
            cout << primes[i] << " ";
        }
    }

    if (number != 1) {
        cout << number << endl;
    }
}

int main(){

	// Calcular factores primes
	vector<int> primes;
	fill_sieve(primes);

	cout << "Primeros 30 números primos" << endl;
	for (int i = 0; i < 30; i++) {
		cout << primes[i] << " ";
	}
	cout << "\n\n";
	cout << "Total de números primos hasta " << MAX << ": " << primes.size() << "\n\n";

	int N = 1435756;
	cout << "Factores primes de: " << N << "\n";
	get_prime_factors(N, primes);
	cout << "\n";

	int A = 270, B = 192;
	printf("GCD(%d, %d) = %d\n", A, B, gcd(A, B));
	printf("MCM(%d, %d) = %d\n", A, B, A*B / gcd(A, B));

	return 0;
}

