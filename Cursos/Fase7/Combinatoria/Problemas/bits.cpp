/**
 * https://omegaup.com/arena/problem/OMI-2020-Bits
 *
 * @autor Esaú Peralta
 * @email esau.opr@gmail.com
 **/

#include <iostream>

using namespace std;

#define i64 long long

i64 P_T[5001][5001]; // Pascal's triangle
const i64 MOD = 1000000007;

void fill_pascal_triangle(int n) {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == i || j == 0) {
                P_T[i][j] = 1;
            } else {
                P_T[i][j] = (P_T[i - 1][j - 1] + P_T[i - 1][j]) % MOD;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int ka, kb, n_bits;
    cin >> n_bits >> ka >> kb;

    if (kb > ka) {
        swap(ka, kb);
    }

    fill_pascal_triangle(n_bits);

    if (ka == kb) {
        // Total of Pairs  = Ways to put ka bits in N spaces * Ways to put kb bits in N spaces
        // Pairs where the numbers are equal = n_C_Ka
        // Total of Pairs - Pairs where the numbers are igual
        cout << (P_T[n_bits][ka] * P_T[n_bits][ka] - P_T[n_bits][ka]) % MOD << endl;
        return 0;
    }

    i64 ans = 0;
    for (int f_bit = 0; f_bit < n_bits; f_bit++) { // Fixed bit
        // start from -> kb - (n_bits - f_bit)
        // bits to place - (available spaces to the rigth)
        // Example  kb=5 - (n_bits-f_bit)=2 -> Minimun 3 bits must be placed to the left so you
        // can't place 0, 1, or 2 bits to the left
        for (i64 left_bits = max(0, kb - (n_bits - f_bit)); left_bits <= min(kb - 1, f_bit); left_bits++) {
            i64 l_ways = P_T[f_bit][left_bits];
            i64 r_ways_a = P_T[n_bits - f_bit - 1][ka - left_bits];
            i64 r_ways_b = P_T[n_bits - f_bit - 1][kb - left_bits - 1];

            ans += ((l_ways * r_ways_a) % MOD * r_ways_b)%MOD;
            ans %= MOD;
        }
    }

    cout << ans << endl;

  return 0;
}
