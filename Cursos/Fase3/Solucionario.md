# Solución a los problemas de primavera

## Problema A - Lada

**Descripción**

Nos daran una serie de ladas telefónicas y debemos imprimir el lugar al que pertenece.

**Solución**

El problema no tiene mayor dificultad. Usamos condicionales IF para saber que lugar debemos
imprimir.

[Link al codigo](./A.%20Lada/main.cpp)

## Problema B - Encuentra el mayor
**Descripción**
Dada una serie de números, tenemos que encontrar cuál es el mayor.

**Solución**

El primer entero en los datos de entrada nos indica cuántos números son en total.
El primer conflicto que nos encontramos es que el problema no describe el rango de los números
y por lo tanto debemos encontrar una buena forma de incializar nuestra variable en donde
almacenaremos el número más grande. (Aunque parece que son enteros positivos).

Por ejemplo, ¿Qué pasa si inicializamos nuestro número mayor con cero y los datos son todos enteros
negativos? Si realizamos las comparaciones al final tendremos que el mayor es cero, pero es
incorrecto puesto que el mayor es alguno de los números negativos de la entrada.

Por ello, una buena inicialización es leer el primer número de la lista y usarlo como mayor.
Posteriormete podemos leer los números restantes y realizar las comparaciones correspondientes.

[Link al codigo](./B.%20Encuentra%20el%20mayor/main.cpp)

## Problema C - Herencia

**Descripción**
Enunciado clave:
>Si las monedas no pueden ser divididas en `N` partes idénticas, entonces
las partes fueron divididas en lo más cercano posible a que fueran idénticas: cada parte
difiere de la otra por una moneda, a lo mucho. En ese caso, la hija indica que tomo una
de las partes más pequeñas para ella.

**Solución**
La cantidad de monedas que sobra es la herencia que se repartira entre las hijas restantes,
es decir: `herencia = residuo / (hijas - 1)`  <---- división entera.

Solo existen 2 casos que considerar:
   1. Si la division es exacta, entonces la herencia que tomo la hija pequeña pudo haber sido
la misma que las otras hijas o una unidad menos (en caso que el total de monedas hubiera
sido un numero no divisible entre el total de hijas)
   2. Si la division es inexacta, entonces el total inicial de monedas tambien era inexacto,
por lo que la hija pequeña solo pudo haber tomado la cantidad resultante al efectuar la
division entera de residuo  `(hijas - 1)`

[Link al codigo](./C.%20Herencia/C_Herencia.cpp)

## Problema D - Tablero de ajedrez

**Solución**
Considera la siguiente imagen:

<img src="./D.%20Ajedrez/ajedrez.png" width="300">

Si enumeramos las columnas del 1 al 8, donde `'a'=1`, `'b'=2`... `'h'=8`, podemos notar la siguientes propiedades:
- Cuando el indice de la columna es **impar**, entonces todos los indices de las filas **impares** corresponden a una casilla negra. Mientras que los indices de las filas **pares** son blancas. (Observa la columna marcada en rojo)
- Cuando el indice de la columna es **par**, entonces todos los indices de las filas **impares** corresponden a una casilla blanca. Mientras que los indices de las filas **pares** son negras. (Observa la columna marcada en verde)

Dicho de otra forma:
- La casilla es negra si se cumple alguna de las siguientes condiciones:
   - La columna es impar y la fila es impar.
   - La columna es par y la fila es par.
- La casilla es blanca si se cumple alguna de las siguiente condiciones:
   - La columna es impar y la fila es par.
   - La columna es par y la fila es impar.

[Link al codigo](./D.%20Ajedrez/ajedrez.cpp)

## Problema E - Bardeando

**Descripción**: https://omegaup.com/arena/problem/pb-Bardeando/

El problema consiste en calcular la cantidad faltante de longitud de trozos para cubrir cierto perímetro.

Nos dan `n` trozos y cada trozo tiene cierta longitud.


**Solución**

- Debemos sumar la cantidad de perímetro que podemos cubrir, para ello usamos un ciclo.
- Calculamos la diferencia `Perimetro - suma`. Si la diferencia es negativa tenemos longitud de trozos de sobra.

[Link al código](./E.%20Bardeando/main.cpp)

## Problema F - Estaciones de Radio

**Descripción**: https://omegaup.com/arena/problem/estacion

El problema consiste en dada una frecuencia inicial en particular, debemos encontrar la estación de
radio más cercana de las 5 estaciones que nos proporcionan.

Si la frecuencia inicial no está dentro del rango imprimimos la palabra "error",
si no, imprimimos la distancia la frencuencia más cercana y si está adelante o detrás.

Nota: Si hay dos estaciones a la misma distancia debemos tomar la más a la derecha.


**Solución**

- Para solucionar el problema basta con calcular la distancia a cada estación y quedarnos con la que más pequeña.
- En caso de que haya distancias iguales, para quedarnos con la más a la derecha basta con recorrer las estaciones en orden ascendente y usar `<=` a nuestra comparación.
- Usamos el signo de la distancia para saber si está a la derecha o izquierda
- Nota que para conservar el signo de la distancia todo el tiempo usamos la función `abs` para obtener el valor absoluto al momento de hacer nuestra comparaciones.

[Link al código](./F.%20Estaciones%20de%20Radio/main.cpp)

## Problema G - Maxima Calificación

**Descripción**: https://omegaup.com/arena/problem/Maxima-calificacion/

El problema consiste en dado 3 numeros encontrar el mayor de los 3


**Solución**

La solución al problema es comparar los 3 numeros
`a` > `b` y `a` > `c`  => `a` es mayor
`b` > `a` y `b` > `c` => `b` es mayor
si no `c` es mayor

[Link al código](./G.%20Maxima%20Calificacion/main.cpp)

## Problema H - Numeros NO Fibonacci

**Descripción**: https://omegaup.com/arena/problem/nofib/#problems

El problema consiste en dado un numero entero `a` escribir todos los numeros menores a `a` que no pertenecen a la susesion


**Solución**

- hay que primero encontrar los numeros que si pertenecen a la sucesion
- debemos guardar el valor anterior de la suma así como el nuevo valor de la suma
- usamos estos 2 valores como rango para  imprimir  los valores que no se encuentran en la sucesion simpre y cuando el valor sea menor al que nos indicaron

[Link al código](./H.%20Numeros%20NO%20Fibonacci/main.cpp)

## Problema I - Construccion de un triangulo

**Descripción**: https://omegaup.com/arena/problem/DRMIGTriangulo/

El problema consiste en determinar si es posible o no, construir un triangulo dadas las longitudes de sus 3 lados.
Nos van a dar 3 enteros que son el tamaño de cada uno de los lados de nuestro supuesto triangulo que tenemos que validar si es posible o no crear.
Tenemos que devolver SI o NO respectivamente si es posible crear dicho triangulo.
Observar que nos dan en la entrada numeros decimales, por lo que pueden ser enteros o con punto flotante por lo que hay que asegurarnos que las variables que ocupemos puedan soportar numeros con punto decimal (float, double).

**Solución**

Si hacemos varios ejemplos nos damos cuenta que en efecto hay longitudes con las que no podemos construir un triangulo. Necesitamos de una herramienta que nos ayude a comprobar si se puede construir dicho triangulo, y para ello utilizamos el teorema de la desigualdad triangular.

<img src="./I.%20Construccion%20de%20un%20Triangulo/teorema.png" width="300">

El teorema de la desigualdad triangular dice que: `En todo triángulo la suma de las longitudes de dos lados cualquiera es siempre mayor a la longitud del lado restante`. Este hecho es una consecuencia de otro teorema de la geometría plana clásica que afirma que la distancia más corta entre dos puntos es la línea recta.

Tomando como base el teorema, sabemos que podemos construir un triangulo si las longitudes cumplen con dicho teorema, entonces tenemos que para todas las combinaciones posibles de pares de longitudes tenemos que aplicar dicho teorema.

```c++
x + y > z
x + z > y
y + z > x
```

Si todas estas afirmaciones son verdaderas, sabemos que con las longitudes que tenemos podemos construir un triangulo. Si cualquiera de ellas es falsa, ya no cumple con el teorema y entonces ya no podemos construir un triangulo.

[Link al código](./I.%20Construccion%20de%20un%20Triangulo/main.cpp)

## Problema J - Intervalo

**Descripción**: https://omegaup.com/arena/problem/Intervalo/

En este problema nos van a dar 3 numeros (A,B,C) y tenemos que determinar si C esta contenido en el rango entre A y B o si se encuentra fuera de ese rango en que posición se encuentra, si a la derecha o a la izquierda.

**Solución**

Podemos imaginarnos los 3 numeros como posiciones en una linea recta, e imaginar que las posiciones A y B dictan el inicio y fin de un rango que es donde debemos comprobar si se encuentra C. Al problema solo le interesan 3 posibilidades, si C se encuentra adentro, hacia la izquierda o la derecha del intervalo dictado por A-B.

**Adentro del intervalo**:
Por lo que para saber si C se encuentra entre A y B, tenemos que saber si C es mayor o igual que A y menor o igual que B al mismo tiempo.

**Izquierda**:
Para saber si se encuentra hacia la izquierda, nos basta con saber si C es menor que A. Ya que si C es menor que A tambien es menor que B, por lo tanto C es menor que ambos y esta a la izquierda en nuestra linea recta.

**Derecha**:
Para saber si se encuentra hacia la derecha, podemos comparar si C es mayor que B. Ya que si C es mayor que B tambien es mayor que A, por lo tanto C es mayor que ambos y esta a la derecha en nuestra linea recta.

[Link al código](./J.%20Intervalo/main.cpp)

## Problema K - Normal

**Solución**

Dada la descripción tenemos que simular una distribución normal con números enteros.
Como entrada tenemos un número N que indica el máximo de la distribución. Tenemos que empezar desde
1 hasta N y una vez llegado a N tenemos que ir de N a 1. De esa manera podemos imprimir en pantalla
la distribución de 1 hasta N y de N hasta 1.

[Link al código](./K.%20Normal/normal.cpp)

## Problema L - El caracol

**Descripción**

Nos dicen que el caracol tiene que subir una cantidad P de metros para salir de un pozo.
Todos los días logra subir S metros y cada noche resbala R metros. Por lo que tenemos que
calcular en cuantos días podría salir del pozo.

**Solución**

Tenemos que hacer un ciclo en el que cada iteración corrresponde a un día y una noche.
Continuaremos el ciclo mientras la cantidad de metros avanzada sea menor que la profundidad del pozo.
Si el caracol no ha podido salir, tenemos que restar los metros que éste resbala cada noche.

[Link al código](./L.%20El%20caracol/el_caracol.cpp)

## Problema M - Si te da

**Descripción**: https://omegaup.com/arena/problem/siteda

El problema consiste en iterar sobre una secuencia cuyo siguiente elemente está formado por tomar la unidad del resultado de la suma de los dos anteriores.

La secuencia termina cuando volvamos a los dos primeros números iniciales.

Debemos imprimir la secuencia y el número de elementos formados.


**Solución**

- Para solucionar el problema podemos simular la secuencia.
- Usaremos el operador de módulo para obtener el siguiente elemento.
- Para imprimir la secuencia podemos hacerlo por partes, es decir, al  generar cada elemento de la secuencia.
- Observa que usamos una variable auxiliar $tmp$ para no perder níngún elemento de la secuencia.

[Link al código](./M.%20Si%20te%20da/main.cpp)

## Problema N - Cubote

**Descripcion**

El problema nos dice que nos daran `N` * `N` * `N` cubos, es decir si `N` = 5, tendriamos `5`*`5`*`5`= `125` cubos.
Utilizando esta cantidad de cubos, se deben acomodar en una mesa de tal forma que se forme un cubo mas grande (cubote). Imagina que son bloques lego, y se quieren juntar para crear un cubo que tenga `N` bloques por lado.

El reto es encontrar la forma de acomodarlos de tal manera que las caras visibles tengan los valores minimos.

**Solucion**

Uno de los primeros pasos es entender que es una _cara visible_ del cubo.

Considera las siguientes imagenes. En la primera se presenta un cubo sobre una mesa azul.
Como se observa, la cara inferior esta en contacto con la mesa, por lo tanto **NO es visible** desde ningun angulo. Cualquiera de las otras caras son visibles. La cara invisible esta sombreada en azul.

En la segunda imagen, se han colocado 2 cubos, uno al lado del otro. En este caso, ambos cubos tienes 2 caras invisibles: una es la que esta en contacto con la mesa (sombra azul), mientras que la otra se oculta al colocar un cubo al lado del otro (sombra verde.)

<img src="./N.%20Cubote/cubo_mesa.png" width="300">
<img src="./N.%20Cubote/2cubo_mesa.png" width="300">

Ahora bien, podemos asumir que si se pusiera un cubo encima de otro, se taparia tambien la cara superior del cubo de abajo. Observa la siguiente imagen, en la que se han colocado 2 cubos encima de otros 2. El area roja sorresponde a la nueva cara invisible.

<img src="./N.%20Cubote/3cubo_mesa.png" width="300">

Es importante notar que mientras mas cubos se coloquen al lado de otro, se incrementan las caras invisibles.

Se deja como ejercicio al lector deducir las siguientes conjeturas:
1. En el cubote, los cubos de las esquinas superiores tienen 3 caras visibles.
2. En el cubote, los cubos de las aristas tienes 2 caras visibles.
3. En el cubote, los cubos que no estan ni en las esquinas ni aristas solo tienen 1 cara visible.

Con base en las conjeturas anteriores, se puede plantear una solucion al problema de la siguiente manera:

Dados los valores de las caras, encontrar las combinaciones de caras con el minimo valor. Es decir calcular las siguientes variables:
`minUnaCara`, `minDosCaras` y `minTresCaras`.
Para hacerlo, es necesario considerar la posicion en la que se encuentran los valores. Por ejemplo, para `minDosCaras` NO es posible usar los valores de las caras `A` y `F` ya que no estan juntas.

<img src="./N.%20Cubote/valores_cubo.png" width="300">

Posteriormente, se deben calcular la cantidad de cubos que habra en las esquinas superiores y la cantidad total de aristas visibles:
`cubosEnEsquinasSuperiores` y `cubosEnAristas`.

Nota que `cubosEnEsquinasSuperiores` siempre sera `4` para todos los cubotes con `N > 1`.
Observa la siguiente imagen, en donde la sombra roja representa los cubos en las esquinas superiores, mientras que la verde representa las aristas.

```c++
cubosEnEsquinasSuperiores = 4;
```

<img src="./N.%20Cubote/cubote3.png" width="300">

Para hacer el calculo de estas variables basta con hacer algunos casos a mano y encontrar un patron que relacione a la variable `N`.

Tip: Nota que empezando por el nivel del cubote que toca la mesa, existen 4 cubos en las aristas y este patron se repite excepto en el nivel superior.

```c++
cubosEnAristas = (N-2) * 8 + 4;
```

La ultima variable que queda por calcular es `cubosConUnaCara`, la cual se refiere a aquellos cubos que no son ni aristas ni esquinas. Esta es simple:
```c++
cubosConUnaCara = (N-2) * (N-2) * 5 + (N-2) * 4;
```

Finalmente, la suma total de las caras visibles seria:

```c++
int total = 0;
total += minUnaCara * cubosConUnaCara;
total += minDosCaras * cubosEnAristas;
total += minTresCaras * cubosEnEsquinasSuperiores;
```

En el caso de ejemplo que se proporciona, se tendrían los siguientes valores:

```
minUnaCara = 1
minDosCaras = 3
minTresCaras = 6

cubosConUnaCara = 0
cubosEnAristas = 4
cubosEnEsquinasSuperiores = 4
```

```c++
int total = 0;
total += minUnaCara * cubosConUnaCara;              // 1 * 0 = 0
total += minDosCaras * cubosEnAristas;              // 3 * 4 = 12
total += minTresCaras * cubosEnEsquinasSuperiores;  // 6 * 4 = 24
cout << total // 36
```


[Link al código](./N.%20Cubote/main.cpp)



## Problema O - Playeras de Navidad

**Descripción**: https://omegaup.com/arena/problem/Playeras-de-Navidad/

El problema en sí consiste en determinar el total que se pagó al comprar 4 grupos de playeras de tallas `CH`, `M`, `G` y `EG`. Cada talla con diferente precio

**Solucion**
El reto de este problema es leer la entrada, ya que se combinan enteros y caracteres.

Se puede abordar de diferentes maneras, pero la mas simple es utilizar `cin`.

```c++
int cantidad;
char talla;
cin >> cantidad >> talla;
```

Nota que en el segmento de código de arriba, el `cin` se engará de leer correctamente un entero y guardarlo en la variable `cantidad`, mientras que el caracter será guardado en `talla`. Esto puede leer sin problemas valores del tipo `1000M`, `0G` y cualquier combinacion que tenga un entero seguido por **un solo caracter**.

Para resolver el problema en el que hay dos caracteres, por ejempl para `CH`, simplemente usamos un `if` en `talla` para ver si es `C` o `E`, ya que en estos casos sabemos que el siguiente valor es un caracter, el cual podemos simplemente leer y guardar en una variable extra.

Ahora el codigo se veria asi:
```c++
int cantidad;
char talla;
char basura;
cin >> cantidad >> talla;
if(talla == 'C' || talla == 'E') {
   cin >> basura; // Leer el caracter adicional
}
```
Para hacer la suma del total, simplemente usamos un `switch` o `if` para determinar el precio de acuerdo a la talla y multiplicar por la cantidad.

Nota adicional: Recuerda que el orden en que se da la entrada es distinto, es decir podria ser `5CH 2M 3G 4EG` pero tambien `2M 3G 5CH 4EG`.

[Link al código](./O.%20Playeras%20de%20Navidad/playeras_navidad.cpp)
