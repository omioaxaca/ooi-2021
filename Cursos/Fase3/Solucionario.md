# Solución a los problemas de primavera

## Problema A - Lada

## Problema B - Encuentra el mayor

## Problema C - Herencia

Enunciado clave: Si las monedas no pueden ser divididas en `N` partes idénticas, entonces
las partes fueron divididas en lo más cercano posible a que fueran idénticas: cada parte
difiere de la otra por una moneda, a lo mucho. En ese caso, la hija indica que tomo una
de las partes más pequeñas para ella.

La cantidad de monedas que sobra es la herencia que se repartira entre las hijas restantes,
es decir: `herencia = residuo / (hijas - 1)`  <---- división entera.

Solo existen 2 casos que considerar:
   1. Si la division es exacta, entonces la herencia que tomo la hija pequeña pudo haber sido
la misma que las otras hijas o una unidad menos (en caso que el total de monedas hubiera
sido un numero no divisible entre el total de hijas)
   2. Si la division es inexacta, entonces el total inicial de monedas tambien era inexacto,
por lo que la hija pequeña solo pudo haber tomado la cantidad resultante al efectuar la
division entera de residuo  `(hijas - 1)`

[Link al codigo](./C_Herencia.cpp)

## Problema D - Ajedrez

## Problema E - Bardeando

**Descripción**: https://omegaup.com/arena/problem/pb-Bardeando/

El problema consiste en calcular la cantidad faltante de longitud de trozos para cubrir cierto perímetro.

Nos dan $n$ trozos y cada trozo tiene cierta longitud.


**Solución**

- Debemos sumar la cantidad de perímetro que podemos cubrir, para ello usamos un ciclo.
- Calculamos la diferencia $Perimetro - suma$. Si la diferencia es negativa tenemos longitud de trozos de sobra.