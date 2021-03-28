// Comparando número de galaxias
// https://omegaup.com/arena/problem/Comparando-numero-de-galaxias/

#include <iostream>

using namespace std;

int main() {

    int regionA = 0;
    int regionB = 0;
    int regionC = 0;

    cin>>regionA;
    cin>>regionB;
    cin>>regionC;


    //Condicion1:
    if (regionA < regionB) {
        cout<<"True ";
    } else {
        cout<<"False "<<endl;
    }

    //Condicion2:
    if (regionC > regionA) {
        cout<<"True ";
    } else {
        cout<<"False ";
    }

    //Condicion3:
    if (regionA == regionB) {
        cout<<"True ";
    } else {
        cout<<"False ";
    }

    //Condicion4:
    if (regionA != regionC) {
        cout<<"True ";
    } else {
        cout<<"False ";
    }

    //Condicion5:
    if (regionC <= regionB) {
        cout<<"True";
    } else {
        cout<<"False";
    }

    return 0;
}
