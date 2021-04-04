#include<iostream>

using namespace std;

int main() {
	
	// LECTURA DE DATOS:
	float ladoA = 0;
	float ladoB = 0;
	float ladoC = 0;
	
	cin>>ladoA;
	cin>>ladoB;
	cin>>ladoC;
	
	// PROCESAMIENTO
	bool esPosible = false;
	
	// Aplicando el teorema de la desigualdad del triangulo.
	if (ladoA + ladoB > ladoC &&
	    ladoA + ladoC > ladoB &&
		ladoC + ladoB > ladoA ) {
		
		esPosible = true;
	}
	
	
	// IMPRESION:
	if (esPosible) {
		cout<<"SI"<<endl;
	} else {
		cout<<"NO"<<endl;
	}
	
	return 0;
}