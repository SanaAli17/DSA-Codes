#include <iostream>
#include <queue>
#include <stack>
#define MAXVER 5
using namespace std;

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

    void print_graph() {
        cout << "\nAdjacency Matrix Representation:\n";
        for (int i = 0; i < MAXVER; ++i)
            for (int j = 0; j < MAXVER; ++j)
                if (g[i][j].adj)
                    cout << "Edge from " << i << " to " << j << " with weight " << g[i][j].weight << endl;
    }

    void DFS(int start) {
        bool visited[MAXVER] = { false };

        cout << "\n\nDFS Traversal: ";
        dfsUtil(start, visited);
        cout << endl;
    }

    void dfsUtil(int v, bool visited[]) {

        visited[v] = true;
        cout << v << " ";

        for (int i = 0; i < MAXVER; ++i)
            if (g[v][i].adj && !visited[i])
                dfsUtil(i, visited);
    }

    void BFS(int start) {

        bool visited[MAXVER] = { false };
        queue<int> q;

        cout << "\n\nBFS Traversal: ";
        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int v = q.front(); q.pop();
            cout << v << " ";

            for (int i = 0; i < MAXVER; ++i) {
                if (g[v][i].adj && !visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        cout << endl;
    }
};

int main() {
    Graph gr;

    gr.join_edge(0, 1, 15);
    gr.join_edge(0, 2, 25);
    gr.join_edge(1, 3, 36);
    gr.join_edge(2, 4, 45);

    gr.print_graph();

    gr.DFS(0);
    gr.BFS(0);

    return 0;
}
