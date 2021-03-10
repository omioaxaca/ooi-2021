// Mayor o menor de edad
// https://omegaup.com/arena/problem/Mayor-o-menor-de-edad/#problems

#include<iostream>

using namespace std;

int main () {

    int nacimiento = 0;

    cin>>nacimiento;

    int edad = 2020 - nacimiento;

    if (edad >= 18) {
        cout<<"MAYOR DE EDAD";
    } else {
        cout<<"MENOR DE EDAD";
    }

    return 0;
}