/*
  https://omegaup.com/arena/problem/minecraft

  @autor Esaú Peralta
  @email esau.opr@gmail.com
*/

#include <bits/stdc++.h>

using namespace std;

#define Coord pair<int, int>
#define Node pair<int, Coord>

const int movs[] = {1, 0, 0, 1, -1, 0, 0, -1};

bool is_valid(int pi, int pj, int rows, int cols) {
    if (pi < 0 || pi >= rows || pj < 0 || pj >= cols) {
        return false;
    }
    return true;
}

int bfs(vector<string> & field, Coord start, Coord end, int rows, int cols) {
    // priority_queue<Node> queue; // De mayor a menor
    priority_queue<Node, vector<Node>, greater<Node>> queue; // De menor a mayor

    queue.push(make_pair(0, start));
    field[start.first][start.second] = '#';

    while(!queue.empty()) {
        Node node = queue.top();
        queue.pop();

        int time = node.first;
        Coord coord = node.second;

        for (int i = 0; i < 8; i+=2) {
            int pi = coord.first + movs[i];
            int pj = coord.second + movs[i+1];

            if (pi == end.first && pj == end.second) { // LLegamos
                if (field[pi][pj] == '.') {
                    return time + 1;
                } else {
                    return time + field[pi][pj] - '0' + 1;
                }
            }

            if (!is_valid(pi, pj, rows, cols) || field[pi][pj] == '#') { // No se puede pasar
                continue;
            }

            if (field[pi][pj] == '.') { // Solo toma un paso
                queue.push(make_pair(time+1, make_pair(pi, pj)));
            } else { // Toman x pasos destruir + 1 de avanzar
                queue.push(make_pair(time + field[pi][pj] - '0' + 1, make_pair(pi, pj)));
            }

            field[pi][pj] = '#'; // Marcamos como visitado haciendolo pared
        }
    }

    return -1;
}


int main() {
    int rows, cols;
    int si, sj, ti, tj;

    cin >> rows >> cols;
    cin >> si >> sj >> ti >> tj;

    vector<string> field;
    string str;

    for (int i = 0; i < rows; i++) {
        cin >> str;
        field.push_back(str);
    }

    cout << bfs(field, make_pair(si-1, sj-1), make_pair(ti-1, tj-1), rows, cols) << endl;

    return 0;
}
