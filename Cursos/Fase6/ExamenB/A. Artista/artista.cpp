// https://omegaup.com/arena/problem/artista
// Solucion: Crear una matriz de pilas para simular las acciones.
// La pila se usa para representar los pedazos de papel que se apilan uno sobre otro.
// Nota que pegar un papel adhesivo equivale a remover el papel de hasta arriba de la pila.
#include <bits/stdc++.h>

using namespace std;

// Declarar la matriz que representa la cartulina inicial. Cada celda contiene una pila de enteros para
// representar los colores.
stack<int> cartulina[201][201]; // Utilizar un tamaño constante equivalente al máximo posible.
// Esto tambien podria hacerse con un vector de vectores:
//   vector< vector< stack<int> > > cartulina(201, vector<stack<int>>(201);
int filas, columnas;

void imprimir() {
    // Imprimir el estado de la cartulina
    for (int i = 1; i <= filas; ++i) {
        for (int j = 1; j <= columnas; ++j) {
            if (!cartulina[i][j].empty()) {
                cout << cartulina[i][j].top() << " ";
            }
            else {
                cout << "-1 ";
            }
        }
        cout << "\n";
    }
}

int main() {
    int grosor, color_cartulina;
    cin >> columnas >> filas;
    cin >> grosor >> color_cartulina;

    // Agregar todas las capas iniciales a la cartulina (correspondientes al grosor)
    for (int i = 1; i <= filas; ++i) {
        for (int j = 1; j <= columnas; ++j) {
            for (int g = 0; g < grosor; ++g) {
                cartulina[i][j].push(color_cartulina);
            }
        }
    }

    // Leer los rectangulos y simular las acciones
    int num_rectangulos;
    cin >> num_rectangulos;
    for (int r = 0; r < num_rectangulos; ++r) {
        int color;
        int rec_filas, rec_cols;
        int x, y; // Esquina superior izquierda del rectangulo
        cin >> color >> rec_cols >> rec_filas;
        cin >> x >> y;
        
        // Realizar las operaciones correspondientes para el rectangulo
        for (int i = 0; i < rec_filas; ++i) {
            for (int j = 0; j < rec_cols; ++j) {
                stack<int>& pila = cartulina[y + i][x + j]; // Acceder por referencia a la pila en la casilla correspondiente
                if (color != -1) {
                    // Agregar una parte del rectangulo a esta casilla
                    pila.push(color);
                }
                else {
                    // Es una tira adhesiva, entonces remover de la pila
                    if (!pila.empty()) {
                        pila.pop();
                    }
                }
            }
        }
    }

    // Imprime el estado de la cartulina
    imprimir();

    return 0;
}