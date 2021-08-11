// https://omegaup.com/arena/problem/k-esimo-primo#problems
// @autor Esaú Peralta
// @email esau.opr@gmail.com

#include <iostream>
#include <cstdio>
#include <vector>
#include <bitset>

#define MAX 2000000 // Hasta este número hay al menos 140000 primos
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

int main(){
    int N, num;
    // Calcular factores primes
    vector<int> primes;
    fill_sieve(primes);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> num;
        cout << primes[num-1] << "\n";
    }

    // cout << primes.size() << endl;

    return 0;
}
