#include <iostream>

using namespace std;

int main() {
  int max;
  cin >> max;
  int i;
  for(i = 1; i <= max; i++) {
    cout << i << ' ';
  }
  for (i = max - 1; i >= 1; i--) {
    cout <<  i << ' ';
  }
}
