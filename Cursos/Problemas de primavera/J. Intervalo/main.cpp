#include<iostream>

using namespace std;

int main() {
	
	// LECTURA DE DATOS:
	int inicio = 0;
	int final = 0;
	int posicion = 0;
	
	cin>>inicio;
	cin>>final;
	cin>>posicion;
	
	// PROCESAMIENTO E IMPRESION
	
	// Si la posicion esta entre inicio y final.
	if (posicion >= inicio && posicion <= final) {
		cout<<"INTERVALO"<<endl;
	} else if (posicion < inicio) { // si esta a la derecha
		cout<<"IZQUIERDA"<<endl;
	} else if (posicion > final) { // si esta a la izquierda
		cout<<"DERECHA"<<endl;
	}
	
	return 0;
}