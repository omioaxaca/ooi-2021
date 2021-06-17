# Soluciones al 3er examen eliminatorio de la OOI 2021

- Link: https://omegaup.com/arena/ooi-2021-e3/#problems

## Temas:
 - Matrices
 - Recursión
 - Aritmética modular
 - Búsqueda binaria

## A. Proyectiles
El problema nos da dos series de coordenadas X/Y, tenemos que verificar si las coordenadas de la segunda serie son iguales o diferentes de las que nos dan en la primer serie. Saber si ya habíamos visto una coordenada anteriormente o no.

Al ser dos coordenadas pudieramos tener un espacio de dos dimensiones donde podamos guardar si previamente ya habíamos visto una coordenada de la siguiente forma `espacio[x][y] = 1` de esta forma marcamos en esa coordenada una visita para posteriormente con la segunda serie de coordenadas hacer la comparación `if (espacio[x][y] == 1)` quiere decir que ya lo hemos visitado. Para esto necesitaríamos una matriz de tamaño (INT_MAX * INT_MAX) ya que necesitamos poder guardar hasta el mayor numero de coordenada posible, esta solución no es eficiente en memoria, por lo que no va a ser una solución valida ya que nos excedemos del limite de memoria permitido.

Tenemos que encontrar la forma de emular lo mismo pero solo con las coordenadas que nos dan, sin tener que ocupar espacio de memoria extra. Para eso podemos guardar las coordenadas en un Vector de tamaño N de vectores de tamaño 2. Donde almacenamos cada coordenada (x,y) en un vector de tamaño 2 y eso en un vector. Terminamos con algo asi:
`espacio = [[2,3], [2,9], [0,1], [1,2]]`

Necesitamos una forma de buscar las nuevas coordenadas en el vector que ya tenemos. Podemos intentar una fuerza bruta, para cada nueva coordenada ir a buscar en todo el conjunto de coordenadas que ya tenemos a ver si alguna es igual en X y Y. Pero esto resulta en una complejidad cuadratica que por tiempo el juez nos evaluaría pocos puntos.

Que pasaría si ordenamos la entrada? Si la ordenamos cambia algo en nuestro problema? La respuesta es que si, gracias a que la entrada ahora esta ordenada tomando como prioridad x y luego y. Podemos aplicar una busqueda binaria modificada para ir buscando la coordenada x y una vez encontrada ver si tambien y es igual, si no podemos irnos a la izquierda o a la derecha segun sea el caso y así amortizar nuestra complejidad a `O(nlogn)` que entra perfecto en tiempo.

Link al codigo: [Click](./A.%20Proyectiles/proyectiles.cpp)

## B. Recursión con memorización

Este problema plantea una función recursiva, la cuál debe evaluarse tal y como se especifica. Sin embargo, es necesario considerar que la relación recursiva presenta traslapes, es decir, un mismo estado se puede evaluar más de una vez.

Para evitar calcular el mismo estado durante varias ocasiones, podemos memorizar o guardar los resultados ya obtenidos.

Dado que el problema presenta 3 variables en el estado, necesitamos una arreglo de 3 dimensiones, para así poder almacenar todas las combinaciones.

Planteamiento recursivo:

- Estado: `a`, `b`, `c`
- Casos base:
   - Si el minimo entre `a`, `b` y `c` es menor o igual que `3`, entonces el resultado es `a + 2b + 3c`.
   - Si el minimo entre `a`, `b` y `c` es mayor que `3` y `a + b + c = 100` entonces el resultado es `0`.
- Paso recursivo: El resultado es `f(a - 1, b - 1, c - 1) + f(a, b - 3, c - 3) + f(a / 2, b, c)`.

El arreglo de memoria debe ser declarado para almacenar los valores extremos de las variables, en este caso al menos 100 localidades para cada una.

```c++
unsigned long long int memoria[101][101][101];
```

Lo que la combinacion de indices guarda, es el resultado de evaluar la funcion. Por ejemplo: `memoria[3][7][2]` guarda el resultado de evaluar `f(3, 7, 2)`.

Nota que el tipo de dato que se usa es `unsigned long long int`, ya que el problema nos asegura que puede haber valores tan grandes como 2<sup>64</sup>.

También, se nos pide que reportemos el resultado módulado a 2<sup>64</sup>. Aquí pasa algo interesante, podríamos usar aritmética modular en cada una de las operaciones, sin embargo, al ser el módulo 2<sup>64</sup> y el tipo de dato `unsigned long long int`, el resultado se automodula, ya que cuando la variable se desborda al llegar al valor máximo, vuelve a ser 0.

Por último, se nos pide contar la cantidad de llamadas recursivas únicas, esto se consigue de forma fácil al incrementar un contador cada vez que se actualiza el valor de la memoria.

Un dato adicional: Nuestra memoria debe iniciar en un valor inválido, para que de esta forma podamos averiguar si ya se consultó ese estado o no. Dado que el rango de valores válidos está entre `0` y 2<sup>64</sup>, entonces no nos queda ningun valor inválido. Para solucionar esto, utilizamos otra memoria que se inicializa a `false`, y se actualiza a `true` cada que se ha visitado un estado.

```c++
bool estadosUsados[101][101][101] = {false};
```

Link al codigo: [Click](./B.%20Recursion%20con%20memorizacion/memorizacion.cpp)

## C. Coeficiente binomial recursivo

## D. Submatrices

El problema nos pide que encontremos todas las submatrices contenidas en la matriz grande. Para hacerlo simplemente tenemos que tomar la matriz pequeña y buscarla por toda la matriz grande, empezando de izquierda a derecha y de arriba a abajo.

En la imagen se observa el caso de ejemplo, con las submatrices marcadas en colores.
Nota que para que se considere una identica, todos los elementos deben ser iguales a la submatriz.

<img src="./D.%20Submatrices/submatrices.png" width="300">

La solución requiere un buen manejo de los índices.

Link al codigo: [Click](./D.%20Submatrices/submatrices.cpp)