// Teclas del nokia.
// https://omegaup.com/arena/problem/Serial_Nokia/#problems
// Problema de implementacion, manejos de cadenas e indices.
#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

// Utilizar un vector de strings para representar las teclas
vector<string> teclado = {"0 ",
                          "1.",
                          "2abc",
                          "3def",
                          "4ghi",
                          "5jkl",
                          "6mno",
                          "7pqrs",
                          "8tuv",
                          "9wxyz"
};

int main() {
    string palabra;
    bool mayusculas = true;

    // Leer palabra por palabra mientras existan en la entrada
    while(cin >> palabra) {
        for (int i = 0; i < palabra.length(); ++i) {
            // Empezar a contar las occurrencias contiguas del caracter de la posicion i
            char valor = palabra[i];
            int cont = 0;
            int j = i;
            while (j < palabra.length() && palabra[j] == valor) {
                cont++;
                j++;
            }

            // Si el valor es #, entonces activar/desactivar las mayusculas.
            if (valor == '#') {
                // El valor cambia solo si la cantidad de veces que se presiona
                // la tecla es impar. Ya que si fuera par, se regresa al mismo estado.
                if (cont % 2)
                    mayusculas = !mayusculas;
            }
            else {
                // Convertir el valor a entero, aprovechando las propiedades del codigo ASCII
                int numero = valor - '0';
                // Obtener la posicion de la letra.
                //   Se resta 1 al contador porque el indice comienza en 0.
                //   Se utiliza modulo en caso de que el digito se presione varias veces.
                //      Ejemplo, presionar el 3 por 6 veces es lo mismo que presionarlo 2 veces.
                int letra_idx = (cont - 1) % teclado[numero].size();
                char letra = teclado[numero][letra_idx];
                
                // Verificar si las mayusculas estan activadas y convertir la letra.
                if (mayusculas) {
                    letra = toupper(letra); // Conteida en libreria cctype
                }

                // Imprimir la letra.
                cout << letra;
            }
            // Ya se contaron todos los caracteres hasta j, por lo tanto
            // incrementar el valor de i. El -1 es necesario por que i es
            // aumentado en el ciclo for.
            i = j - 1;
        }
    }

    return 0;
}