# Temario para la Olimpiada Oaxaqueña de Informática 2021

El objetivo del temario es preparar a los competidores para su participación en la Olimpiada Mexicana de Informática, abordando todos los temas mínimos necesarios. 

Es importante recalcar que, aunque se trata de utilizar un lenguaje de programación, el material de preparación debe estar enfocado en fomentar la lógica y creatividad para resolver problemas utilizando algoritmos. Es decir, durante la olimpiada no se pretende que los alumnos dominen el lenguaje de programación, sino que sean capaces de plantear soluciones a problemas a través de algoritmos.

El temario se divide en 3 partes:
- **Lógica matemática**: El objetivo es presentar la lógica y creatividad para resolver problemas y acertijos desde una perspectiva diferente para fomentar la destreza y el pensamiento lógico.
- **Introducción a C++**: Durante esta parte se pretende que los alumnos aprendan a programación básica usando C++, cubriendo temas simples como entrada y salida, hasta condicionales y ciclos.
- **Algoritmos y solución de problemas con programación**: Esta es la parte más extensa, dónde se cubren algoritmos, estructuras de datos y otros temas necesarios para la OMI.

## Parte 1: Lógica matemática
- ¿Cómo resolver un problema?
    - Lectura sugerida para entrenadores: https://www.olimpiadadeinformatica.org.mx/OMI/OMI/archivos/apuntes/ResolverUnProblema.pdf
- Algoritmos. Definición y conceptos.
- Modelar un problema como entrada, proceso y salida.

En este apartado no se plantean temas formales de lógica, sin embargo, se presentan varios problemas que pueden ser utilizados para fomentar el pensamiento lógico de los estudiantes.

Se sugiere que los alumnos resuelvan los problemas de nivel cadete del canguro matemático:
- Se requieren conocimientos de algebra y aritmética.
NOTA: Los problemas de geometría se pueden ignorar, ya que este tema no es evaluado en la OMI.

http://www.ommenlinea.org/actividades/concursos/canguro-matematico/#PrevCad

http://www.ommenlinea.org/wp-content/uploads/practica/canguro/cadete17.pdf
http://www.ommenlinea.org/wp-content/uploads/practica/canguro/cadete18.pdf

http://www.ommenlinea.org/wp-content/uploads/practica/folletos/Introductorio_34.pdf


## Parte 2: Introducción a C++

Notas previas:

- Los temas propuestos aquí son los mínimos requeridos para el resto de la olimpiada. No existe una bibliografía específica. El material sugerido corresponde a los videos del canal Programación ATS, los cuales han sido revisados por el comité y se ha acordado utilizarlos para reforzar los temas.
- Se pretende que los ejercicios utilizados se enfoquen a la resolución de problemas lógicos.
- Se recomienda leer la guía de [convención de estilos](./ConvencionEstilos.md) antes de abordar el temario.
- Usar Omegaup para evaluar todos los ejercicios. Más información acerca de las ventajas aquí https://omegaup.com/course/Curso-OMI/assignment/COMI-intro/#problems/COMI-Objetivo 

### Temas
| Tema | Material | Notas |
|-------|--------|---------|
| Introducción a plataforma Omegaup| https://omegaup.com/course/Curso-OMI/assignment/COMI-intro/#problems | Usar Omegaup como plataforma oficial para evaluar los ejercicios |
| Estructura básica de un programa | https://www.youtube.com/watch?v=ld4nzao5XAc ||
| Tipos de datos y variables | https://www.youtube.com/watch?v=xBOpQN8jR54 ||
| Entrada y salida de datos | https://www.youtube.com/watch?v=1iQUZEklWio | Hacer enfasis en que para la OOI no se requiere pedir los datos al usuario explicitamente, es decir no usar `cout << "Inserte un numero"`|
| Operadores arimeticos | https://www.youtube.com/watch?v=rpZVq8LRb0U | |
| Operadores lógicos | https://www.youtube.com/watch?v=75c1_7eHdlY | |
| Operadores de igualdad y relacionales | https://www.youtube.com/watch?v=thoXz7vYE4k | |
| Prioridad de operadores | https://www.youtube.com/watch?v=s7OZpNf49qE | |
| Estructuras de selección | https://youtu.be/r5GbMsB0eOA https://youtu.be/V_fdETm_QMI | Usar la sentencia  `if`. El `switch` no es relevante en este punto. | 
| Estructuras de repetición | https://www.youtube.com/watch?v=DTmMjJ-cd00 https://www.youtube.com/watch?v=vHKWMR2WaIQ https://www.youtube.com/watch?v=_6AdtcVn4xs https://youtu.be/yNWuEDd8iQs | Uso de `while`,`do-while` y `for` |

## Parte 3: Algoritmos y solución de problemas con programación
Lista de temas
- Estructuras de datos simples
    - Arreglos de 1 dimensión utilizado `std::vector`.
    - Manipulacion de indices (indexar, arrego circular)
    - Ordenamiento. `std::sort`.
- Manipulación de caracteres.
    - `std::string`
    - Codigo ASCII y conversion entre tipos de dato `char` e `int`.
- Funciones
    - Ventajas de las funciones
    - Funciones que reciben parametros por valor
- Arreglos de 2 dimensiones (Matrices)
    - Representacion usando `std::vector` y forma primitiva
    - Acceder a las posiciones fila y columna, utilizando modulos
    - Suma de matrices
- Recursión
    - Funciones matemáticas recursivas

    - Recursión para problemas no matemáticos (ventanas, calificaciones recursivas)

    - Recursión con memorización

- Complejidad de un  algoritmo

    - Notación O(n)

- Aritmética modular

    - Exponenciación rápida

    - Elevar `a` a la `n` molulo `m`

- Búsqueda binaria

    - Recursiva

    - Iterativa

    - Lower bound y upper bound

- Creación de nuevos tipos de datos usando struct

- Pilas

    - Concepto básico

    - Implementación manual

    - std::stack

    - Problema de los paréntesis balanceados

    - Histograma

- Búsqueda en profundidad (DFS)

    - Representación gráfica con árbol de decisiones

    - Todas las sumas posibles en un arreglo

    - DFS en dos dimensiones

- Backtracking

    - Problema de las 8 reinas

- Colas

    - Concepto básico

    - Implementación manual

    - std::queue

- Búsqueda en amplitud (BFS)

    - Representación gráfica con árbol de decisiones

    - BFS en dos dimensiones

- BFS y colas de prioridad

- Mapas std::map

- Barridos

    - Uso de cubetas (problema xor, sumas de parejas = k)

- Árboles

- Grafos

- Problemas interactivos

- Problemas de solo salida

- Programación dinámica

- Listas ligadas

- Sets

- Two pointers

- Matemáticas y lógica (IMPORTANTE)

    - Exámenes pasados de la OMI

    - Optimización de problemas usando matemáticas

    - Factorización prima

    - Módulos

    - Precálculo

    - Combinatoria (principio del conteo, casillas)

- Manipulación de strings y caracteres

    - Palindromos

    - Subcadenas

    - Prefijos y sufijos

- Misceláneos

    - Buenas prácticas de programación

    - Paso de parámetros por referencia

    - Librería bits/stdc++

    - Optimizar entrada y salida con cin y cout

    - Leer de archivos

    - Uso de C++11