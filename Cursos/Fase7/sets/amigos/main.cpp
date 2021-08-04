// https://omegaup.com/arena/problem/amigos

// @autor Esaú Poralta
// @email esau.opr@gmail.com

#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    map<string, int> participants;
    set<pair<int, int>> friendships;

    int np, cases, relation;
    string tmp;

    cin >> np;
    // Asignamos un identificador a cada participante guardamos la asignación en el mapa
    for (int i = 0; i < np; i++) {
        cin >> tmp;
        participants[tmp] = i;
    }

    // Leemos las relaciones y las guardamos
    for (int i = 0; i < np; i++) {
        for (int j = 0; j < np; j++) {
            cin >> relation;
            if (relation == 1) {
                friendships.insert(make_pair(i,j));
            }
        }
    }

    cin >> cases;
    string name1, name2;

    // Por cada caso obtenemos su identificador y consultamos si tienen una relación
    while (cases--) {
        cin >> name1 >> name2;
        if (friendships.find(make_pair(participants[name1], participants[name2])) != friendships.end()) {
            cout << "1\n";
        } else {
            cout << "0\n";
        }
    }

    return 0;
}
