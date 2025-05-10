#include <iostream>
using namespace std;

class Vertex; 

class Edge {

public:

    Vertex* end_vertex;
    int weight;
    Edge* next;

    Edge(Vertex* end, int wt, Edge* nt) : end_vertex(end), weight(wt), next(nt) {}
};

class Vertex {

public:

    char data;
    Vertex* next_vertex;
    Edge* edge_list;

    Vertex(char d, Vertex* nt = nullptr) : data(d), next_vertex(nt), edge_list(nullptr) {}

    void connect_to(Vertex* dst, int wt) {

        edge_list = new Edge(dst, wt, edge_list);
    }

    void print_edges() {

        Edge* temp = edge_list;

        while (temp) {

            cout << data << " --> " << temp->end_vertex->data << " (weight: " << temp->weight << ")" << endl;
            cout << endl;

            temp = temp->next;
        }
    }
};

class Graph {

private:
    Vertex* first_vertex;

public:
    Graph() : first_vertex(nullptr) {}

    Vertex* find(char data) {

        Vertex* temp = first_vertex;

        while (temp && temp->data != data)
        {
            temp = temp->next_vertex;
        }

        return temp;
    }

    bool add_vertex(char data) {

        if (find(data)) {
            return false;
        }

        first_vertex = new Vertex(data, first_vertex);

        return true;
    }

    bool add_edge(char from, char to, int wt) {
        Vertex* v1 = find(from);
        Vertex* v2 = find(to);

        if (!v1 || !v2) {
            return false;
        }

        v1->connect_to(v2, wt);
        return true;
    }

    void print_graph() {
        cout << "\n>> Adjacency List Representation:\n\n";

        Vertex* temp = first_vertex;

        while (temp) {

            temp->print_edges();

            temp = temp->next_vertex;
        }
    }
};

int main() {
    Graph gr;

    gr.add_vertex('W');
    gr.add_vertex('X');
    gr.add_vertex('Y');
    gr.add_vertex('Z');

    gr.add_edge('W', 'X', 14);
    gr.add_edge('X', 'Z', 3);
    gr.add_edge('W', 'Y', 21);
    gr.add_edge('Y', 'Z', 12);

    gr.print_graph();

    return 0;
}
