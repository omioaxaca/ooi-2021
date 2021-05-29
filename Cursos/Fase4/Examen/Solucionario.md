# Soluciones al 2do examen eliminatorio de la OOI 2021

- Link: https://omegaup.com/arena/ooi-2021-e2/#problems

## A. Potencias de 2
El problema es simple de entender, solo se requiere elevar `2` a la `n` potencia. El mayor desafío es el tamaño máximo de `n`, ya que puede ser hasta 265, lo cual definitivamente no cabe en un `int` o `long long int`.

En el siguiente enlace, se pueden consultar los valores máximos soportados por cada tipo de dato: https://ooi.gitbook.io/courses/temario/untitled/tipos-de-datos-y-variables

Lo que se pretende con este problema es que se haga la implementación manual utilizando un arreglo para almacenar los digitos del resultado.

Es decir, se comienza con:

- 2 a la 0 = `{1}`

- 2 a la 1 = `{2}`

- 2 a la 2 = `{4}`

- 2 a la 3 = `{8}`

- 2 a la 4 = `{1, 6}` <-- Nota que el 16 se representa separado por digitos.

...

- 2 a la 10 = `{1, 0, 2, 4}` <-- Nota que el 1024 se representa separado por digitos.

Recordemos que elevar a la `n` potencia es lo mismo que multiplicar el numero `n` veces.

En resumen, se puede resolver el problema utilizando un arreglo para almacenar el resultado de la multiplicación y continuar haciendolo `n` veces.

La manera de hacer la multiplicación es dígito por dígito (tal y como se haría en papel).

Ejemplo:
```
    5 1 2
x       2
---------
  1 0 2 4
   
```

Es importante considerar el acarreo. Así se conoce al numero que se pasa al siguiente lugar decimal, es decir al multiplicar 5 x 2 el resultado es 10, sin embargo se escribe el 0 y decimos que llevamos 1. Este 1 es el acarreo. Otro ejemplo, 6 x 7 = 42 se escribe el 2 y llevamos 4.

## B. Teclas del Nokia
## C. Moscas
## D. Acomoda el numero