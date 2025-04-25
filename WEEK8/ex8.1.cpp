#include <iostream>
#include <stdexcept>
using namespace std;

#define NUMNODES 500


template <typename T>

struct TreeNode {

    T info;
    int left;
    int right;
    int father;
};


template <typename T>

class BinaryTree {
private:

    TreeNode<T> BT[NUMNODES];  
    int root;                  
    int next_available;              

public:
    
    BinaryTree() {

        root = -1;
        next_available = 0;
    }

   
    bool IsEmpty() const {

        return root == -1;
    }

   
    int create_node(T info, int l = -1, int r = -1, int father = -1) {

        if (next_available >= NUMNODES) {

            throw overflow_error("OOPS ! Tree node limit exceeded :( ");
        }

        BT[next_available] = { info, l, r, father };

        return next_available++;
    }

   
    void create_root(T info) {

        if (!IsEmpty()) {

            throw logic_error("OOPS! Root already exists :( ");
        }

        root = create_node(info);
    }

    T Data(int node_index) const {

        if (node_index < 0 || node_index >= next_available) {

            throw out_of_range("OOPS! Invalid node index :( ");
        }

        return BT[node_index].info;
    }

    void set_left_child(int parent_index, T info) {

        int left_index = create_node(info, -1, -1, parent_index);

        BT[parent_index].left = left_index;
    }


    void set_right_child(int parent_index, T info) {

        int right_index = create_node(info, -1, -1, parent_index);

        BT[parent_index].right = right_index;
    }




    int left_child(int node_index) const {

        if (node_index < 0 || node_index >= next_available) {

            throw out_of_range("OOPS! Invalid node index :( ");
        }

        return BT[node_index].left;
    }


    int right_child(int node_index) const {

        if (node_index < 0 || node_index >= next_available) {

            throw out_of_range("OOPS! Invalid node index :(");
        }
        return BT[node_index].right;
    }


    int get_root_index() const {
        return root;
    }
};

int main() {

    BinaryTree<int> tree;

    tree.create_root(15);

    int root_index = tree.get_root_index();

    tree.set_left_child(root_index, 9);
    
    tree.set_right_child(root_index, 17);

    cout << "\n>> Root: " << tree.Data(root_index) << endl;
    cout << "\n>> Left Child: " << tree.Data(tree.left_child(root_index)) << endl;
    cout << "\n>> Right Child: " << tree.Data(tree.right_child(root_index)) << endl;

    int left_index = tree.left_child(root_index);  

    tree.set_left_child(left_index, 5);         
    tree.set_right_child(left_index, 3);        

    cout << "\n>> Left->Left: " << tree.Data(tree.left_child(left_index)) << endl;
    cout << "\n>> Left->Right: " << tree.Data(tree.right_child(left_index)) << endl;

    int right_index = tree.right_child(root_index);

    tree.set_left_child(right_index, 2);
    tree.set_right_child(right_index, 8);

    cout << "\n>> Right->Left: " << tree.Data(tree.left_child(right_index)) << endl;
    cout << "\n>> Right->Right: " << tree.Data(tree.right_child(right_index)) << endl;

    return 0;
}

