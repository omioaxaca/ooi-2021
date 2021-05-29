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

Este problema es muy retador, el más complicado del exámen ya que require de un buen análisis del problema y creatividad para implementar la solución.

Primero que nada, lo que se nos pide es identificar los rangos en que se alcanzó la mayor población de moscas, es decir cuando había más moscas vivas.

Imaginemos que se tienen 3 moscas, con los siguientes rangos de vida:

A: 2 - 5
B: 4 - 7
C: 3 - 6

Observa la siguiente imagen, en donde se representa una linea de tiempo y las vidas de cada mosca.

<img src="./C.%20Moscas/moscas1.png" width="400">

Ahora observa en esta otra imagen, como se han contado la cantidad de moscas vivas durante el tiempo (color naranja). Asi mismo, observa que se ha marcado en azul el rango donde se encontró la mayor población de moscas equivalente a 3 moscas del tiempo 4 al 5.

<img src="./C.%20Moscas/moscas2.png" width="400">

### Solución A

Podemos utilizar un vector para marcar el periodo de vida de cada mosca, similar a lo que hicimos en las imágenes. Es decir, si una mosca nace en el tiempo `t_n` y muere en `t_m`, podriamos hacer lo siguiente:

```c++
vector<int> moscas_vivas_en_tiempo(60001); // El problema dice que el tiempo maximo es de 0 hasta 60,000

// Aqui iria la parte de leer los datos

// Para esta mosca, marcar su tiempo de vida
for (int i = t_n; i < t_m; ++i) {
  moscas_vivas_en_tiempo[i]++; // Incrementar la cantidad de moscar vivas en el tiempo i
}
```

Una vez que se tiene el vector marcado, se puede recorrer para encontrar el valor maximo.
```c++
int maximo = 0;
for (int i = 1; i <= 60000; ++i) {
  if (moscas_vivas_en_tiempo[i] > maximo) {
    maximo = moscas_vivas_en_tiempo[i];
  }
}
```

Finalmente, tenemos que buscar los rangos en que se encuentra el valor maximo

```c++
for (int i = 1; i <= 60000; ++i) {
  int inicio_rango;
  int fin_rango;
  if (moscas_vivas_en_tiempo[i] == maximo) {
    inicio_rango = i; // Aqui inicia el rango
    // Incrementar el valor de i mientras sea igual al maximo
    while (i <= 60000 && moscas_vivas_en_tiempo[i] == maximo) {
      i++;
    }
    // Ahora i tiene el valor del final del rango
    fin_rango = i;
    // Imprimir el rango
  }
}
```

[Código](C.%20Moscas/moscasA.cpp)

Esta solución es correcta, sin embargo fallaría al ejecutarse dentro del tiempo establecido ya que puede haber hasta 20,000 moscas y en el caso de que todas tuvieran un rango de vida de 1 hasta 60,000. Entonces recorreriamos 20,000 veces el vector completo de 60,000 posiciones, lo cual equivale a 1,200,000,000 operaciones.

Dado que el tiempo del problema es de 1 segundo, debemos asumir que podemos realizar a lo mas 100,000,000 operaciones. Por lo tanto, este algoritmo fallaría con TLE. Nota que este tiempo es subjetivo a las capacidades de cómputo del juez Omegaup.

## Solución B

Podemos optimizar la solución anterior si evitamos marcar por completo todo el rango de vida de las moscas. En su lugar, podemos usar 3 vectores. Uno que nos indique el tiempo de nacimiento de cada mosca. Mientras que otro indique el tiempo de la muerte de cada mosca. Finalmente, tendriamos el arreglo de tiempos (similar a la solucion anterior), pero esta vez lo llenaremos de una forma distinta.

Para contar la cantidad de moscas vivas, procederemos a recorrer el arreglo de tiempo de nacimiento e incrementaremos un contador cada que encontremos un nuevo tiempo de inicio y lo disminuiremos de acuerdo al arreglo de tiempos de muerte. El valor del contador lo guardaremos en el vector de moscas vivas durante el tiempo.

```c++
vector<int> nacimientos(60001);
vector<int> muertes(60001);
vector<int> moscas_vivas_en_tiempo(60001);

// Aqui iria la parte para leer datos y llenar los arreglos

int contador = 0;
for (int i = 1; i <= 60000; ++i) {
  contador += nacimientos[i]; // El contador incrementa de acuerdo a la cantidad de moscas que nacieron en el tiempo i
  contador -= muertes[i];     // El contador disminuye de acuerdo a la cantidad de moscas que murieron en el tiempo i
  moscas_vivas_en_tiempo[i] = contador; // La cantidad de moscas vivas en el tiempo i equivale al valor del contador
}
```

El resto de los pasos para encontrar los rangos máximos es igual a la solución anterior.

[Código](C.%20Moscas/moscasB.cpp)


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