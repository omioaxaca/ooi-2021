/*
    https://omegaup.com/arena/problem/Cantidad-de-factores-primos

    @autor Esaú Peralta
    @email esau.opr@gmail.com
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <bitset>

#define MAX 1001 // sqrt(10^6)
using namespace std;


void fill_sieve(vector<int> &primes) {
    bitset<MAX> sieve;

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

int count_divisors(int number, vector<int> &primes) {
    int divisors = 1;

    for (int i = 0; i < primes.size() && primes[i] * primes[i] <= number; i++) {
        int factor_times = 1;
        while (number % primes[i] == 0) {
            number /= primes[i];
            factor_times ++;
        }
        divisors *= factor_times;
    }

    if (number != 1) {
        divisors*=2;
    }

    return divisors;
}

int main(){
    int N, num;
    // Calcular factores primes hasta la raiz del máximo posible
    vector<int> primes;
    fill_sieve(primes);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> num;
        cout << count_divisors(num, primes) << "\n";
    }

    return 0;
}
