#include <iostream>
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

    bool is_adjacent(int v1, int v2) {

        return g[v1][v2].adj;
    }

    void join_edge(int v1, int v2, int wt) {

        g[v1][v2].adj = true;
        g[v1][v2].weight = wt;

    }

    void remove_edge(int v1, int v2) {
        g[v1][v2].adj = false;
        g[v1][v2].weight = 0;
    }

    
    int get_weight(int v1, int v2) {

        if (g[v1][v2].adj)
        {
            return g[v1][v2].weight;
        }

        return -1;
    }

    void print_graph() {

        cout << "\nAdjacency Matrix Representation: \n\n";

        for (int i = 0; i < MAXVER; ++i) {

            for (int j = 0; j < MAXVER; ++j) {

                if (g[i][j].adj)
                {
                    cout << "Edge from " << i << " to " << j << " with weight " << g[i][j].weight << endl;
                }
            }
        }
    }
};

int main() {

    Graph gr;

    gr.join_edge(0, 3, 15);
    gr.join_edge(0, 1, 13);
    gr.join_edge(2, 3, 38);
    gr.join_edge(4, 1, 25);

    gr.print_graph();

    cout << "\n>> Does edge exists from 0 to 3: " << (gr.is_adjacent(0, 3) ? "Yeah :) " : "Nope :(" ) << endl;

    cout << "\n>> Weight of Edge from 4 to 1: " << gr.get_weight(4, 1) << endl;

    gr.remove_edge(2, 3);

    cout << "\n>> After Removing Edge from 2 to 3:\n";

    gr.print_graph();

    return 0;
}
