// CICLOS - ITERACIONES
//  FOR       - PARA
//  WHILE     - MIENTRAS
//  DO WHILE  - HACER MIENTRAS
//

#include <iostream>

using namespace std;

int main() {
    /*  FOR:
        Iterador con una variable auxiliar.

        Necesita de:
        1- variable auxiliar de iteracion;
        2- condicion de funcionamiento;
        3- incr./decr. de var. auxiliar;
    */
    int veces = 100;
    for (int iteracion = 1; iteracion <= veces; iteracion++) {
        cout<<"Iteracion: "<<iteracion<<endl;
    }

    cout<<"TERMINO EL CICLO"<<endl;

   /*  WHILE
        Primero compara y luego ejecuta el codigo dentro del bloque.

        Necesita de:
        1- condicion de ciclo
    */

    int veces = 10;
    int iteracion = 1;
    while(iteracion <= veces) {
        cout<<"Iteracion: "<<iteracion<<endl;
        iteracion++;
    }

    /* DO WHILE
        Primero ejecuta el codigo dentro del bloque y despues compara.

        Necesita de:
        1- condicion de ciclo
    */

    int veces = 10;
    int iteracion = 1;
    do {
        cout<<"Iteracion: "<<iteracion<<endl;
        iteracion++;
    } while (false);

    return 0;
}