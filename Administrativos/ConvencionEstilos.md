# Convención del código fuente para la OOI 2021

El presente documento enuncia algunas de la convenciones utilizadas para los códigos de ejemplo que se comparten con los alumnos. La finalidad es utilizar un estilo similar para evitar confusiones relacionadas al lenguaje.

## IDE
- El IDE oficial es Visual Studio Code. Se puede usar algún otro editor para las clases, pero es preferible compilar y debuggear usando VS Code.
- Separar el código fuente en archivos `.cpp` independientes, es decir NO usar proyectos para crear los códigos.

## Lenguaje
- El lenguaje oficial es C++, y para la OOI se utiliza C++11 debido a sus beneficios. Es importante no utilizar código de C que pueda confundir a los competidores.

- Incluir la libreria `#include <bits/stdc++.h>` como estándar, la cual incluye todas las otras librerias. En caso de ser necesario mencionar de forma explícita alguna librería, usar el estilo de C++. Es decir `<cmath>` en vez de `<math.h>`

## Idioma
- Usar español para todas las variables, nombres de funciones y comentarios.

## Estructura general
- Un comentario breve al inicio del codigo (puede ser el link a un problema de Omegaup).
- Librerias
- Utilizar `using namespace std;`
- Usar `main` sin argumentos y retornar 0.
    Ejemplo:
    ```c++
    // Estructura general de un codigo en C++
    // NombreProblema: Enlace a Omegaup
    #include <bits/stdc++.h>

    using namespace std;

    int main() {

        // Codigo aqui

        return 0;
    }

    ```
- Utilizar funciones para modular el código, que sean bien definidas y nombradas.

## Entrada y salida
- Utilizar `cin` y `cout`.
- Usar entrada estandar de la consola.
- Para leer o escribir a archivo, usar la consola del S.O.:
    - `codigo.exe < entrada.in > salida.out`

## Variables
- Utilizar nombres representativos para cada variable o adaptarlos al problema que se busca resolver.
- Declarar solo una variable por linea.
- Inicializar las variables a un valor por defecto.
- Utilizar camelCase o guion bajo `_` para separar palabras.

    Ejemplo:

    ```c++
    int numNodos = 0;
    int numAristas = 0;

    cin >> numNodos >> numAristas;

    bool esValido = validarGrafo(numNodos, numAristas);
    ```
- Alcance (scope)
    - Se recomienda siempre usar variables locales.
    - Cuando se requiera usar variables en diferentes funciones, es preferible pasar por referecia.
    - NOTA: Se prefiere usar globales cuando se declaran arreglos estáticos de tamaños muy grandes, para evitar
            errores en tiempo de ejecución.
    ```c++
    vector esPrimo(10000000, false);

    int criba(vector<int>& primos) {
        // ...
    }
    
    int main() {
        vector<int> primos;
        criba(primos);
    }
    ```

## Comentarios
- Utilizar comentarios para describir las partes complejas del codigo.
- Preferir comentarios in-line `//`

## Arreglos de C vs arreglos de C++

## Miscelaneos
- Preferir _foreach_ vs iteradores para recorrer `list`, `map`, `set`.

    Ejemplo:
    ```c++
        for (auto& elemento : miMapa) {
            cout << "llave" << elemento.first;
            cout << "valor" << elemento.second;
        }
    ```

