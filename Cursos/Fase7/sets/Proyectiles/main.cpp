// https://omegaup.com/arena/problem/Proyectiles

// @autor Esaú Poralta
// @email esau.opr@gmail.com

#include <iostream>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    set<pair<int, int>> ship_map;
    int n, k;
    int x, y;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        ship_map.insert(make_pair(x, y));
    }

    for (int i = 0; i < k; i++) {
        cin >> x >> y;
        if (ship_map.find(make_pair(x, y)) == ship_map.end()) {
            cout << "1\n";
        } else {
            cout << "0\n";
        }
    }

    return 0;
}
