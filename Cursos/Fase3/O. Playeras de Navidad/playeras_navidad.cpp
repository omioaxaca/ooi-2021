// https://omegaup.com/arena/problem/Playeras-de-Navidad/
#include <iostream>
#include <string>

using namespace std;

int main() {
	int cantidad = 0;
	char talla;
  char basura;
	int total = 0;

	for(int i = 0;i < 4; i++) {
		cin >> cantidad >> talla;
		if(talla == 'C') {
      cin >> basura; // Leer la H e ignorarla
			total += cantidad * 50;
		}
		else if(talla == 'M') {
			total += cantidad * 60;
		}
		else if(talla == 'G') {
			total += cantidad * 70;
		}
		else if(talla == 'E') {
      cin >> basura; // Leer la G e ignorarla
			total += cantidad * 90;
		}
	}

	cout << total;
	
	return 0;
}