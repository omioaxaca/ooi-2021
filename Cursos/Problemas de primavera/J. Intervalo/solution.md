# Problema J: Intervalo

**Descripción**: https://omegaup.com/arena/problem/Intervalo/

En este problema nos van a dar 3 numeros (A,B,C) y tenemos que determinar si C esta contenido en el rango entre A y B o si se encuentra fuera de ese rango en que posición se encuentra, si a la derecha o a la izquierda.

## Solución

Podemos imaginarnos los 3 numeros como posiciones en una linea recta, e imaginar que las posiciones A y B dictan el inicio y fin de un rango que es donde debemos comprobar si se encuentra C. 
Al problema solo le interesan 3 posibilidades, si C se encuentra adentro, hacia la izquierda o la derecha del intervalo dictado por A-B.
Por lo que para saber si C se encuentra entre A y B, tenemos que saber si C es mayor o igual que A y menor o igual que B al mismo tiempo.
Para saber si se encuentra hacia la izquierda, nos basta con saber si C es menor que A. Ya que si C es menor que A tambien es menor que B, por lo tanto C es menor que ambos y esta a la izquierda en nuestra linea recta.
Para saber si se encuentra hacia la derecha, podemos comparar si C es mayor que B. Ya que si C es mayor que B tambien es mayor que A, por lo tanto C es mayor que ambos y esta a la derecha en nuestra linea recta.

## Código

```c++
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

```
