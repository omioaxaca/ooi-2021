// El foraneo hambriento
// https://omegaup.com/course/ooi_2021_ga/assignment/E01/admin/#problems/Foraneo-hambriento
#include <bits/stdc++.h>

using namespace std;

int main() {
    // Declarar las variables
    int pizzas;
    int amigo_1;
    int amigo_2;
    int amigo_3;
    int amigo_4;
    int amigo_5;
    // Leer la entrada
    cin >> pizzas;
    cin >> amigo_1 >> amigo_2 >> amigo_3 >> amigo_4 >> amigo_5;
    // Hacer los calculos
    int rebanadas = pizzas * 8;
    int rebanadas_comidas = amigo_1 + amigo_2 + amigo_3 + amigo_4 + amigo_5;
    int rebanadas_sobrantes = rebanadas - rebanadas_comidas;

    // Imprimir el resultado
    // SI sobran rebananadas imprimir FF
    // DE LO CONTRARIO impirmir FH
    if (rebanadas_sobrantes > 0) {
        cout << "FF";
    }
    else {
        cout << "FH"; // No sobran rebanadas :(
    }


    return 0;
}


