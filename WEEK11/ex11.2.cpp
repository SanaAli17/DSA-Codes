 #include <iostream>
#include <limits>
using namespace std;

#define MAXVER 5
#define INF INT_MAX

struct Edge {
    bool adj;
    int weight;
};

class Graph {
private:
    Edge g[MAXVER][MAXVER];

public:
    Graph() {
        for (int i = 0; i < MAXVER; ++i)
            for (int j = 0; j < MAXVER; ++j)
                g[i][j] = { false, 0 };
    }

    void join_edge(int v1, int v2, int wt) {
        g[v1][v2].adj = true;
        g[v1][v2].weight = wt;
    }

    void dijkstra(int start) {

        int dist[MAXVER];
        bool visited[MAXVER] = { false };

        for (int i = 0; i < MAXVER; ++i)
            dist[i] = INF;

        dist[start] = 0;

        for (int count = 0; count < MAXVER - 1; ++count) {
            int u = minDistance(dist, visited);
            visited[u] = true;

            for (int v = 0; v < MAXVER; ++v) {
                if (!visited[v] && g[u][v].adj &&
                    dist[u] != INF &&
                    dist[u] + g[u][v].weight < dist[v]) {
                    dist[v] = dist[u] + g[u][v].weight;
                }
            }
        }

        cout << "\nShortest distances from vertex " << start << ":\n";

        for (int i = 0; i < MAXVER; ++i)
            cout << "To " << i << ": " << (dist[i] == INF ? -1 : dist[i]) << endl;
    }

    int minDistance(int dist[], bool visited[]) {
        int min = INF, min_index = -1;

        for (int v = 0; v < MAXVER; ++v)
            if (!visited[v] && dist[v] <= min)
                min = dist[v], min_index = v;

        return min_index;
    }
};

int main() {

    Graph gr;
    gr.join_edge(0, 1, 9);
    gr.join_edge(0, 2, 3);
    gr.join_edge(1, 2, 8);
    gr.join_edge(1, 3, 4);
    gr.join_edge(2, 1, 7);
    gr.join_edge(2, 3, 5);
    gr.join_edge(2, 4, 6);
    gr.join_edge(3, 4, 6);
    gr.join_edge(4, 3, 5);

    gr.dijkstra(0);

    return 0;
}
