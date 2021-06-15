# Soluciones al 3er examen eliminatorio de la OOI 2021

- Link: https://omegaup.com/arena/ooi-2021-e3/#problems

## Temas:
 - Matrices
 - Recursión
 - Aritmética modular
 - Búsqueda binaria

## A. Proyectiles

## B. Recursión con memorización

## C. Coeficiente binomial recursivo

## D. Submatrices

El problema nos pide que encontremos todas las submatrices contenidas en la matriz grande. Para hacerlo simplemente tenemos que tomar la matriz pequeña y buscarla por toda la matriz grande, empezando de izquierda a derecha y de arriba a abajo.

En la imagen se observa el caso de ejemplo, con las submatrices marcadas en colores.
Nota que para que se considere una identica, todos los elementos deben ser iguales a la submatriz.

<img src="./D.%20Submatrices/submatrices.png" width="300">

La solución requiere un buen manejo de los índices.

Link al codigo: [Click](./D.%20Submatrices/submatrices.cpp)