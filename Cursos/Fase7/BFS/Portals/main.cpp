/*
  https://omegaup.com/arena/problem/Portal/#problems

  @autor Esaú Peralta
  @email esau.opr@gmail.com
*/

#include <bits/stdc++.h>

using namespace std;

#define Coord pair<int, int>
#define Node pair<int, Coord>

const int MOVS[] = {1, 0, 0, 1, -1, 0, 0, -1}; // Movimientos 4 adyacentes

#define TOP 0
#define DOWN 1
#define LEFT 2
#define RIGTH 3

int WALL_DIST[4][1300][1300]; // Matriz de precalculos de distancias de cada i,j a sus 4 paredes mas cercanas
int STEPS_MAP[1300][1300]; // Matriz de minimo de pasos para cada i,j

vector<string> FIELD;

bool is_valid(int pi, int pj, int rows, int cols) {
    if (pi < 0 || pi >= rows || pj < 0 || pj >= cols) {
        return false;
    }
    return true;
}

int bfs(Coord start, int rows, int cols) {
    // Varios nodos que llegamos con tiempo T pueden llegar al pastel dependiendo de los saltos
    // Nos quedamos con aquel que llego en menor tiempo
    bool found = false;
    int found_time = INT_MAX;
    int found_parent_time = 0;

    priority_queue<Node, vector<Node>, greater<Node>> queue; // De menor a mayor

    queue.push(make_pair(0, start));
    FIELD[start.first][start.second] = 'b';

    while(!queue.empty()) {
        Node node = queue.top();
        queue.pop();

        int time = node.first;
        Coord coord = node.second;

        // El pastel ya ha sido encontrado y todos los nodos con tiempo t=found_parent_time
        // Asi que si dos de nodos con tiempo t=found_parent_time llegaron al pastel en distinto
        // tiempo por saltos en portales nos quedamos con el que hizo menor tiempo
        if (found && found_parent_time != time) {
            return found_time;
        }

        // Tal cual BFS
        for (int i = 0; i < 8; i+=2) {
            int pi = coord.first + MOVS[i];
            int pj = coord.second + MOVS[i+1];

            if (!is_valid(pi, pj, rows, cols) || FIELD[pi][pj] == '#' || time+1 >= STEPS_MAP[pi][pj]) { // No se puede pasar
                continue;
            }

            if (FIELD[pi][pj] == 'X') {
                found = true;
                found_time = min(found_time, time + 1);
                found_parent_time = time;
            }
            queue.push(make_pair(time+1, make_pair(pi, pj)));
            STEPS_MAP[pi][pj] = time+1;
        }

        // Obtenemos los 4 portales para cada nodo, (distancia, (posición_i, posicion_j))
        int dist = WALL_DIST[TOP][coord.first][coord.second] - 1;
        Node port_up = make_pair(dist, make_pair(coord.first - dist, coord.second));

        dist = WALL_DIST[DOWN][coord.first][coord.second] - 1;
        Node port_down = make_pair(dist, make_pair(coord.first + dist, coord.second));

        dist = WALL_DIST[LEFT][coord.first][coord.second] - 1;
        Node port_left = make_pair(dist, make_pair(coord.first, coord.second - dist));

        dist = WALL_DIST[RIGTH][coord.first][coord.second] - 1;
        Node port_right = make_pair(dist, make_pair(coord.first, coord.second + dist));

        // Move to lower port
        // Minimo de moverse abajo ya sea el camino directo o tomar cualquier de los otros 3 portales
        int min_time = min(port_down.first, min(port_up.first+1, min(port_left.first+1, port_right.first+1)));
        int pi = port_down.second.first;
        int pj = port_down.second.second;
        if (FIELD[pi][pj] == 'X') { // Se llega con un salto, lo guardamos en casi que un nodo con el mismo tiempo
            found = true;           // llegue en un salto más corto
            found_time = min(found_time, time + min_time);
            found_parent_time = time;
        }
        if (FIELD[pi][pj] != '#') { // No es pared
            if (time + min_time < STEPS_MAP[pi][pj]) { // Lo visitamos que caso que lleguemos antes con un salto
                queue.push(make_pair(time + min_time, make_pair(pi, pj)));
                STEPS_MAP[pi][pj] = time + min_time;
            }
        }

        // Move to upper port
        min_time = min(port_up.first, min(port_down.first+1, min(port_left.first+1, port_right.first+1)));
        pi = port_up.second.first;
        pj = port_up.second.second;
        if (FIELD[pi][pj] == 'X') {
            found = true;
            found_time = min(found_time, time + min_time);
            found_parent_time = time;
        }
        if (FIELD[pi][pj] != '#') {
            if (time + min_time < STEPS_MAP[pi][pj]) {
                queue.push(make_pair(time + min_time, make_pair(pi, pj)));
                STEPS_MAP[pi][pj] = time + min_time;
            }
        }

        // Move to right port
        min_time = min(port_right.first, min(port_down.first+1, min(port_left.first+1, port_up.first+1)));
        pi = port_right.second.first;
        pj = port_right.second.second;
        if (FIELD[pi][pj] == 'X') {
            found = true;
            found_time = min(found_time, time + min_time);
            found_parent_time = time;
        }
        if (FIELD[pi][pj] != '#') {
            if (time + min_time < STEPS_MAP[pi][pj]) {
                queue.push(make_pair(time + min_time, make_pair(pi, pj)));
                STEPS_MAP[pi][pj] = time + min_time;
            }
        }

        // Move to left port
        min_time = min(port_left.first, min(port_down.first+1, min(port_up.first+1, port_right.first+1)));
        pi = port_left.second.first;
        pj = port_left.second.second;
        if (FIELD[pi][pj] == 'X') {
            found = true;
            found_time = min(found_time, time + min_time);
            found_parent_time = time;
        }
        if (FIELD[pi][pj] != '#') {
            if (time + min_time < STEPS_MAP[pi][pj]) {
                queue.push(make_pair(time + min_time, make_pair(pi, pj)));
                STEPS_MAP[pi][pj] = time + min_time;
            }
        }
    }

    return found_time;
}

int main() {
    int rows, cols;
    int si, sj;

    cin >> rows >> cols;

    string str;

    for (int i = 0; i < rows; i++) {
        cin >> str;
        FIELD.push_back(str);

        for (int j = 0; j < cols; j++) {
            if(str[j] == 'O') {
                si = i;
                sj = j;
            }
            if (i > 0 && FIELD[i][j] != '#') { // Precalculamos las distancias al muro superior
                WALL_DIST[TOP][i][j] = WALL_DIST[TOP][i-1][j]+1;
            }
            if ( j > 0 && FIELD[i][j] != '#') { // Muro izquierdo
                WALL_DIST[LEFT][i][j] = WALL_DIST[LEFT][i][j-1]+1;
            }
        }
    }

    // Calculamos las distancias de los muros derechos y abajo con un for inverso
    for (int i = rows-1; i >= 0 ; i--) {
        for (int j = cols-1; j >= 0; j--) {
            if (i < rows-1 && FIELD[i][j] != '#') {
                WALL_DIST[DOWN][i][j] = WALL_DIST[DOWN][i+1][j]+1;
            }
            if ( j < cols-1 && FIELD[i][j] != '#') {
                WALL_DIST[RIGTH][i][j] = WALL_DIST[RIGTH][i][j+1]+1;
            }
            STEPS_MAP[i][j] = INT_MAX;
        }
    }

    int steps = bfs(make_pair(si, sj), rows, cols);

    if (steps == INT_MAX) {
        cout << "THE CAKE IS A LIE\n";
    } else {
        cout << steps << endl;
    }

    return 0;
}
