#include <iostream>
using namespace std;


template <typename T>

struct TreeNode {

    T info;
    TreeNode* left;
    TreeNode* right;
    TreeNode* father;

    TreeNode(T value, TreeNode*l = nullptr , TreeNode*r = nullptr , TreeNode* f = nullptr ) : info(value), left(l), right(r), father(f) {}
};

template <typename T>
class BinaryTree {

private:
    TreeNode<T>* root;
    
    void pre_order(TreeNode<T>* node) {

        if (node != nullptr) {

            cout << node->info << " ";

            pre_order(node->left);
            pre_order(node->right);
        }
    }

    void in_order(TreeNode<T>* node) {

        if (node != nullptr) {

            in_order(node->left);
            cout << node->info << " ";
            in_order(node->right);
        }
    }

    void post_order(TreeNode<T>* node) {

        if (node != nullptr) {

            post_order(node->left);
            post_order(node->right);

            cout << node->info << " ";
        }
    }

public:

    BinaryTree() : root(nullptr) {}

    bool IsEmpty() const {

        return root == nullptr;
    }

    TreeNode<T>* GetRoot() const {

        return root;
    }


    void create_root(T data) {

        if (root != nullptr) {

            cout << "OOPS! Root already exists :( " << endl;

            return;
        }

        root = new TreeNode<T>(data);
    }

    void set_left(TreeNode<T>* p, T data) {

        if (p == nullptr) {

            cout << "OOPS! Void Insertion  :(" << endl;
        }
        else if (p->left != nullptr) {

            cout << "OOPS! Invalid Insertion as left exists already :(" << endl;
        }
        else {

            TreeNode<T>* newNode = new TreeNode<T>(data);
            newNode->father = p;
            p->left = newNode;
        }
    }

    void set_right(TreeNode<T>* p, T data) {

        if (p == nullptr) {

            cout << "OOPS! Void Insertion  :(" << endl;
        }
        else if (p->right != nullptr) {

            cout << "OOPS! Invalid Insertion as left exists already :(" << endl;
        }
        else {
            TreeNode<T>* newNode = new TreeNode<T>(data);
            newNode->father = p;
            p->right = newNode;
        }
    }

    void pre_order_traversal() {

        cout << "\n>> PreOrder Traversal: " << endl;
        cout << endl;
        pre_order(root);
        cout << endl;
    }

    void in_order_traversal(){

        cout << "\n>> InOrder Traversal: " << endl;
        cout << endl;
        in_order(root);
        cout << endl;
    }

    void post_order_traversal(){

        cout << "\n>> PostOrder Traversal: " << endl;
        cout << endl;
        post_order(root);
        cout << endl;
    }
};

int main() {

    BinaryTree<int> tree;

    tree.create_root(15);

    TreeNode<int>* root = tree.GetRoot();

    tree.set_left(root, 9);
    tree.set_right(root, 17);

    tree.set_left(root->left, 5);
    tree.set_right(root->left, 3);

    tree.set_left(root->right, 2);
    tree.set_right(root->right, 8);

    tree.pre_order_traversal();
    tree.in_order_traversal();
    tree.post_order_traversal();

    return 0;
}
