// https://omegaup.com/arena/problem/herencia
#include <iostream>

using namespace std;

int main() {
   int herencia = 0;
   int hijas = 0;
   int residuo = 0;
   int tot_min = 0;
   int tot_max = 0;

   cin >> hijas >> residuo;

   herencia = residuo / (hijas - 1);
   if (residuo % (hijas - 1) == 0) {
     tot_min = residuo + herencia - 1;
     tot_max = residuo + herencia;
   }
   else{
     tot_min = residuo + herencia;
     tot_max = tot_min;
   }

   std::cout << tot_min << " " << tot_max << '\n';

   return 0;
}