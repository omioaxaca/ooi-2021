// Como utilizar una matriz
// Una matriz es un arreglo de 2 dimensiones
#include <bits/stdc++.h>

using namespace std;

int main() {
    ///////////////////////////////////////////////////////
    // Vectores - Arreglos de una dimension
    ///////////////////////////////////////////////////////
    // Declaracion de un vector/arreglo
    int vector1[10];            // Estático. Una vez que se le asigna un tamaño NO puede crecer más.
    vector<int> vector2(10);    // Dinámico. Su puede modificar durante tiempo de ejecución.

    // Inicializar un vector/arreglo
    int vector3[10] = {0}; // Asigna 0 a todos los elementos del vector {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    int vector4[10] = {5}; // Asigna 5 al primer elemento del vector    {5, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    int vector5[10] = {1, 2, 7}; // Asigna 1, 2 y 7 al primer, segundo y tercer elemento del vector {1, 2, 7, 0, 0, 0, 0, 0, 0, 0}
    vector<int> vector6(10, 0);  // Crear un vector de 10 elementos y todos valen 0 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    vector<int> vector7(10, 5);  // Crear un vector de 10 elementos y todos valen 5 {5, 5, 5, 5, 5, 5, 5, 5, 5, 5}
    
    ///////////////////////////////////////////////////////
    // Matrices - Arreglos de dos dimensiones
    ///////////////////////////////////////////////////////
    // Declarar una matriz de enteros de 10 filas x 5 columnas.
    int matriz1[10][5]; // Estático
    vector<vector<int>> matriz2; // Dinamico. Matriz vacia
    vector<vector<int>> matriz3(10, vector<int>(5)); // 10 filas x 5 columnas
    vector<vector<int>> matriz4(10, vector<int>(5, 7)); // 10 filas x 5 columnas incializado a 7

    // Rellenar la matriz con numeros crecientes, empezando en el 1
    int filas = 3;
    int columnas = 5;
    vector<vector<int>> m(3, vector<int>(5));

    // Recorrer la primera fila de la matriz e imprimir sus valores
    // for (int j = 0; j < 5; ++j) {
    //     cout << m[0][j];
    // }
    // for (int j = 0; j < 5; ++j) {
    //     cout << m[1][j];
    // }
    // for (int j = 0; j < 5; ++j) {
    //     cout << m[2][j];
    // }
    
    int contador = 1;
    // Recorrer las filas
    for (int i = 0; i < filas; ++i) {
        // Recorrer las columnas
        for (int j = 0; j < columnas; ++j) {
            m[i][j] = contador;
            contador++;
        }
    }

    // Imprimir la matriz
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            cout << m[i][j] << " ";
        }
        cout << "\n";
    }

    
    return 0;
}

