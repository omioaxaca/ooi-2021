/**
 * https://www.hackerrank.com/challenges/bfsshortreach/problem
 *
 * @autor Esaú Peralta
 * @email esau.opr@gmail.com
 **/

#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;


void bfs(int n_nodes, map<int, vector<int>> &G, int s) {
    map<int, int> vis;
    queue<int> cola;
    cola.push(s);
    vis[s] = 0;

    // BFS para recorrer todos los nodos
    while(!cola.empty()) {
        int node = cola.front();
        cola.pop();
        for (auto v : G[node]) {
            if (vis.find(v) == vis.end()) {
                cola.push(v);
                vis[v] = vis[node] + 1;
            }
        }
    }


    // Agregar todos los nodos no visitados con -1
    for (int i =1; i<=n_nodes; i++) {
        if (vis.find(i) == vis.end()) {
            vis[i] = -1;
        }
    }

    // Recorrer el mapa, ya está ordenado en imprimir el costo
    map<int, int>::iterator it;
    for (it = vis.begin(); it!=vis.end(); it++) {
        if (it->first == s) { // No se imprime el nodo inicial
            continue;
        }

        if (it->second == -1) { // No se llegó
            cout << -1 << " ";
        } else {
            cout << it->second * 6 << " ";
        }
    }

    cout << endl;
}

int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int cases;
    cin >> cases;

    while(cases--) {
        int n_nodes, n_edges;
        cin >> n_nodes >> n_edges;

        int node_a, node_b;
        map<int, vector<int>> G;
        for (int i = 0; i < n_edges; i++) {
            cin >> node_a >> node_b;
            G[node_a].push_back(node_b);
            G[node_b].push_back(node_a);
        }

        int start_node;
        cin >> start_node;

        bfs(n_nodes, G, start_node);
    }

    return 0;
}
