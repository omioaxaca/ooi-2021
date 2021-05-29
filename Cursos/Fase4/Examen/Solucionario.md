# Soluciones al 2do examen eliminatorio de la OOI 2021

- Link: https://omegaup.com/arena/ooi-2021-e2/#problems

## Temas:
 - Vectores
 - Cadenas de caracteres (strings)

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

Es importante considerar el acarreo. El cual es el numero que se pasa al siguiente lugar decimal, es decir al multiplicar 5 x 2 el resultado es 10, sin embargo se escribe el 0 en las unidades, y decimos que llevamos 1 para las decenas. Este 1 es el acarreo. Otro ejemplo, 6 x 7 = 42 se escribe el 2 y llevamos 4.

Link a la solución: [Codigo](A.%20Potencias%20de%20dos/potencias.cpp)

## B. Teclas del Nokia

Este tipo de problemas se conocen como de implementación, ya que no se requiere ningún análisis para comprender lo que se pide. Simplemente se debe implementar el código.

La implementación puede ser tediosa, aquí es donde entra la habilidad del programador para diseñar y crear un código limpio y bien estructurado, de tal forma que se simplifique el trabajo de escribir una gran cantidad de código.

Existen varias soluciones, a continuacion se presentan algunas:

Link a la solución: [Codigo](B.%20Teclas%20del%20Nokia/teclasNokia.cpp)

## C. Moscas



## D. Acomoda el numero

Este es el problema más fácil del exámen, se nos pide que encontremos la posicion de cierto elemento dentro del arreglo ordenado de datos.
Muchos pueden irse por la solución de ordenar el arreglo y luego buscar a ese elemento, sin embargo lo más simple es contar la cantidad de elementos menores al número de interés.

Debido a la gran cantidad de datos, este problema necesita una optimización para leer datos cuando se usa `cin`.
Para eso se requiere incluir las siguientes líneas al principio de la función `main`

```c++
ios::sync_with_stdio(false); cin.tie(0);
```

Para más información, consulta https://blog.omegaup.com/trucos-cool/

Link a solución: [Código](D.%20Acomoda%20el%20numero/acomoda.cpp)