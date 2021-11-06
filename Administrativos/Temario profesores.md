# Temario y problemario para profesores OOI 2022

El objetivo del temario es preparar a los profesores asesores de la OOI para tener un mejor dominio en la resolución de problemas de programación competitiva, utilizando algoritmos y técnicas comunes en compentencias como OMI e ICPC.

Así mismo, este temario se basa en el temario de los competidores del año 2021 y a su vez en el temario oficial de la IOI https://ioinformatics.org/files/ioi-syllabus-2019.pdf.

El temario se divide en 2 partes:
- **Lógica matemática**: El objetivo es presentar la lógica y creatividad para resolver problemas y acertijos desde una perspectiva diferente para fomentar la destreza y el pensamiento lógico.

- **Algoritmos y solución de problemas con programación**: Esta es la parte más extensa, dónde se cubren algoritmos, estructuras de datos y otros temas necesarios para la OMI.

## Parte 1: Lógica matemática
- ¿Cómo resolver un problema?
    - Lectura obligatoria para entrenadores: https://www.olimpiadadeinformatica.org.mx/OMI/OMI/archivos/apuntes/ResolverUnProblema.pdf
- Algoritmos. Definición y conceptos.
- Modelar un problema como entrada, proceso y salida.

En este apartado no se plantean temas formales de lógica, sin embargo, se presentan varios problemas que pueden ser utilizados para fomentar el pensamiento lógico.

NOTA: Los problemas de geometría se pueden ignorar, ya que este tema no es evaluado en la OMI.

http://www.ommenlinea.org/actividades/concursos/canguro-matematico/#PrevCad

http://www.ommenlinea.org/wp-content/uploads/practica/canguro/cadete17.pdf
http://www.ommenlinea.org/wp-content/uploads/practica/canguro/cadete18.pdf

http://www.ommenlinea.org/wp-content/uploads/practica/folletos/Introductorio_34.pdf

## NOTA IMPORTANTE

Si no se tiene experiencia previa escribiendo programas para programación competitiva, las siguientes 3 lecturas son obligatorias. Aún si se tiene experiencia, es altamente recomendado revisar la guía de estilos y el texto de complejidad de un algoritmo.

- Leer la guía de [convención de estilos](./ConvencionEstilos.md).
- Leer acerca de complejidad de un algoritmo. https://ooi.gitbook.io/courses/miscelaneos/complejidad-de-un-algoritmo
- Usar Omegaup para evaluar todos los ejercicios. Más información acerca de las ventajas aquí https://omegaup.com/course/Curso-OMI/assignment/COMI-intro/#problems/COMI-Objetivo 
- Introducción a plataforma Omegaup| https://omegaup.com/course/Curso-OMI/assignment/COMI-intro/#problems 

**Acerca de programación dinámica**: A pesar de que el tema de programación dinámica tiene su propia sección y es del apartado avanzado, se sugiere revisar este concepto y algunas técnicas desde el principio. Pues varios de los problemas requieren del uso de esta técnica.

## Parte 2: Algoritmos y solución de problemas con programación

### Estructuras de datos simples
- Arreglos de 1 dimensión utilizado `std::vector`.
- Manipulacion de indices (indexar, arrego circular)
- Ordenamiento. `std::sort`.

- Problemas relacionados
    - https://omegaup.com/arena/problem/Sumar-dos-vectores#problems
    - https://omegaup.com/arena/problem/moscas/#problems
    - https://omegaup.com/arena/problem/N-Impares
    - https://omegaup.com/arena/problem/tienda#problems
    - https://omegaup.com/arena/problem/ptwo#problems

    - https://omegaup.com/arena/problem/Mediana
    - https://omegaup.com/arena/problem/batalla
    - https://omegaup.com/arena/problem/Ordenar#problems

    - https://cses.fi/problemset/task/1068
    - https://cses.fi/problemset/task/1083
    - https://cses.fi/problemset/task/1069
    - https://cses.fi/problemset/task/1094
    - https://cses.fi/problemset/task/1071

### Two pointers

- Problemas relacionados

    - https://leetcode.com/problems/3sum/
    - https://leetcode.com/problems/3sum-closest/
    - https://leetcode.com/problems/trapping-rain-water/
    - https://leetcode.com/problems/find-median-from-data-stream/


### Manipulación de caracteres.
- `std::string`
- Codigo ASCII y conversion entre tipos de dato `char` e `int`.

- Problemas relacionados


### Arreglos de 2 dimensiones (Matrices)
- Representacion usando `std::vector` y forma primitiva
- Acceder a las posiciones fila y columna sabiendo el numero de la casilla y viceversa.
- Suma de matrices

### Recursión
- Funciones matemáticas recursivas

- Recursión para problemas no matemáticos (ventanas, calificaciones recursivas)

- Recursión con memorización


### Aritmética modular

- Exponenciación rápida

- Elevar `a` a la `n` molulo `m`

### Búsqueda binaria

Texto recomendado: https://www.topcoder.com/community/data-science/data-science-tutorials/binary-search/

- Recursiva e iterativa.

- Lower bound y upper bound

- Creación de nuevos tipos de datos usando struct

### Pilas

- Implementación manual usando un contenedor de la STL y punteros.

- std::stack

- Problemas de secuencia monotónica creciente (Histograma).

- Tema extra. Estructuras persistentes en el tiempo (https://youtu.be/23Hil5HJmHE)

### Búsqueda en profundidad (DFS)

- Representación gráfica con árbol de decisiones

- Todas las sumas posibles en un arreglo

- DFS en dos dimensiones

### Backtracking


### Colas

- Implementación manual

- std::queue

### Búsqueda en amplitud (BFS)

- Representación gráfica con árbol de decisiones

- BFS en dos dimensiones


### BFS y colas de prioridad

### Mapas y conjuntos (std::map y std::set)

- Explorar las estructuras ordenadas y no ordenadas. Evaluar ventajas y casos de uso en función de la complejidad.

### Barridos


### Árboles

- BST. Representación usando un contenedor y punteros.
- Explorar temas como Segment Tree, TRIE, Disjoint-Set

### Grafos



- Problemas interactivos

- Problemas de solo salida

### Programación dinámica

Explorar implementación de bottom-up y top-down.

- https://cses.fi/problemset/task/1633
- https://cses.fi/problemset/task/1744
- https://cses.fi/problemset/task/1634
- https://cses.fi/problemset/task/1635
- https://cses.fi/problemset/task/1636

### Listas ligadas



- Matemáticas y lógica (IMPORTANTE)

    - Exámenes pasados de la OMI

    - Optimización de problemas usando matemáticas

    - Factorización prima

    - Módulos

    - Precálculo

    - Combinatoria (principio del conteo, casillas)