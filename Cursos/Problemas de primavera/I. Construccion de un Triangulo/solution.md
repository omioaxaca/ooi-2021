# Problema I: Construcción del triángulo

**Descripción**: https://omegaup.com/arena/problem/DRMIGTriangulo/

El problema consiste en determinar si es posible o no, construir un triangulo dadas las longitudes de sus 3 lados. 
Nos van a dar 3 enteros que son el tamaño de cada uno de los lados de nuestro supuesto triangulo que tenemos que validar si es posible o no crear.
Tenemos que devolver SI o NO respectivamente si es posible crear dicho triangulo.
Observar que nos dan en la entrada numeros decimales, por lo que pueden ser enteros o con punto flotante por lo que hay que asegurarnos que las variables que ocupemos puedan soportar numeros con punto decimal (float, double).

## Solución

Si hacemos varios ejemplos nos damos cuenta que en efecto hay longitudes con las que no podemos construir un triangulo. Necesitamos de una herramienta que nos ayude a comprobar si se puede construir dicho triangulo, y para ello utilizamos el teorema de la desigualdad triangular.

![alt text](/teorema.png "Teorema")

El teorema de la desigualdad triangular dice que: `En todo triángulo la suma de las longitudes de dos lados cualquiera es siempre mayor a la longitud del lado restante`. Este hecho es una consecuencia de otro teorema de la geometría plana clásica que afirma que la distancia más corta entre dos puntos es la línea recta.

Tomando como base el teorema, sabemos que podemos construir un triangulo si las longitudes cumplen con dicho teorema, entonces tenemos que para todas las combinaciones posibles de pares de longitudes tenemos que aplicar dicho teorema.

```c++
x + y > z
x + z > y
y + z > x
```

Si todas estas afirmaciones son verdaderas, sabemos que con las longitudes que tenemos podemos construir un triangulo. Si cualquiera de ellas es falsa, ya no cumple con el teorema y entonces ya no podemos construir un triangulo.


## Código

```c++
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

```
