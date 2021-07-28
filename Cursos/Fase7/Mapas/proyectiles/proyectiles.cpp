#include <bits/stdc++.h>

using namespace std;

struct coord {
    int x, y;
    bool const operator==(const coord &o)const{
        return x == o.x && y == o.y;
    }
    bool const operator<(const coord &o)const {
        return x < o.x || (x == o.x && y < o.y);
    }
};

int main () {
  int numCoordsPasadas;
  cin>>numCoordsPasadas;
  int numCoordsActuales;
  cin>>numCoordsActuales;

  map<coord,bool> coordenadasVistas;

  for (int i = 0; i < numCoordsPasadas; i++) {
    int x, y;
    cin>>x>>y;
    coord c;
    c.x = x;
    c.y = y;
    coordenadasVistas[c] = true;
  }

  for (int i = 0; i < numCoordsActuales; i++) {
    int x, y;
    cin>>x>>y;
    coord c;
    c.x = x;
    c.y = y;
    if (coordenadasVistas.find(c) != coordenadasVistas.end()) {
      cout<<"0"<<endl;
    } else {
      cout<<"1"<<endl;
    }
  }

  return 0;
}