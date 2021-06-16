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

## C. Coeficiente binomial recursivo

## D. Submatrices

El problema nos pide que encontremos todas las submatrices contenidas en la matriz grande. Para hacerlo simplemente tenemos que tomar la matriz pequeña y buscarla por toda la matriz grande, empezando de izquierda a derecha y de arriba a abajo.

En la imagen se observa el caso de ejemplo, con las submatrices marcadas en colores.
Nota que para que se considere una identica, todos los elementos deben ser iguales a la submatriz.

<img src="./D.%20Submatrices/submatrices.png" width="300">

La solución requiere un buen manejo de los índices.

Link al codigo: [Click](./D.%20Submatrices/submatrices.cpp)