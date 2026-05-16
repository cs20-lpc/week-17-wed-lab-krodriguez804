// Implement main program.
// Week 17 Wednesday Homework Krystle Dao

#include <iostream>
#include <vector>
#include <climits>
#include <iomanip>

using namespace std;

const int INF = INT_MAX; // infinity constant

struct Edge {
    int to;
    int weight;
};

void runDijkstra(int vs, int numV, const vector<vector<Edge>>& graph) {
    vector<int> D(numV, INF);    // distance array
    vector<bool> M(numV, false); // marker array

    D[vs] = 0;

    for (int i = 0; i < numV; i++) {
        int vi = -1;
        int minDistance = INF;

        for (int j = 0; j < numV; j++) {
            if (!M[j] && D[j] < minDistance) {
                minDistance = D[j];
                vi = j;
            }
        }

        if (vi == -1) {
            break;
        }

        M[vi] = true;

        for (const auto& edge : graph[vi]) {
            int vj = edge.to;
            int weight = edge.weight;

            int x = D[vi] + weight;

            if (x < D[vj]) {
                D[vj] = x;
            }
        }
    }

    cout << "Shortest distances from source " << vs << ":" << endl;

    for (int i = 0; i < numV; i++) {
        cout << "Node " << i << ": ";
        if (D[i] == INF) 
            cout << "infinity" << endl;
        else 
            cout << D[i] << endl;
    }
}

int main() {
    int numV = 6;
    vector<vector<Edge>> graph(numV);

    graph[0] = {{1, 4}, {2, 9}, {4, 2}};
    graph[1] = {{2, 2}, {3, 1}};
    graph[2] = {{3, 7}, {5, 4}};
    graph[3] = {{5, 1}};
    graph[4] = {{2, 3}, {5, 8}};

    runDijkstra(0, numV, graph);
    runDijkstra(1, numV, graph);

    return 0;
}