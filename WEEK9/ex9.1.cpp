#include <iostream>
#include <fstream>
#include <string>
using namespace std;


template<class ItemType>

struct TreeNode {

    ItemType info;
    TreeNode<ItemType>* left;
    TreeNode<ItemType>* right;
};


template<class ItemType>

class TreeType {

public:

    TreeType();
    ~TreeType();
    bool is_empty() const;
    bool is_full() const;
    int no_of_nodes() const;
    void insert_item(ItemType item);
    void retreive_item(ItemType& item, bool& found) const;
    void print_tree(ofstream& outFile) const;

private:

    TreeNode<ItemType>* root;

    void insert_helper(TreeNode<ItemType>*& ptr, ItemType item);
    void retreive_helper(TreeNode<ItemType>* ptr, ItemType& item, bool& found) const;
    void print_helper(TreeNode<ItemType>* ptr, ofstream& outFile) const;
    void destroy_helper(TreeNode<ItemType>* ptr);
};



template<class ItemType>
TreeType<ItemType>::TreeType() {

    root = NULL;
}

template<class ItemType>
bool TreeType<ItemType>::is_empty() const {

    return (root == NULL);
}

template<class ItemType>
bool TreeType<ItemType>::is_full() const {

    TreeNode<ItemType>* location;
    try {
        location = new TreeNode<ItemType>;
        delete location;
        return false;
    }
    catch (bad_alloc&) {
        return true;
    }
}



template<class ItemType>
int count_nodes(TreeNode<ItemType>* ptr) {

    if (ptr == NULL) {

        return 0;
    }

    return count_nodes(ptr->left) + count_nodes(ptr->right) + 1;
}

template<class ItemType>
int TreeType<ItemType>::no_of_nodes() const {

    return count_nodes(root);
}



template<class ItemType>
void TreeType<ItemType>::insert_item(ItemType item) {

    insert_helper(root, item);
}

template<class ItemType>
void TreeType<ItemType>::insert_helper(TreeNode<ItemType>*& ptr, ItemType item) {

    if (ptr == NULL) {

        ptr = new TreeNode<ItemType>;
        ptr->info = item;
        ptr->left = NULL;
        ptr->right = NULL;
    }

    else if (item < ptr->info) {

        insert_helper(ptr->left, item);
    }
    else if (item > ptr->info) {

        insert_helper(ptr->right, item);
    }
}


template<class ItemType>

void TreeType<ItemType>::retreive_item(ItemType& item, bool& found) const {
    retreive_helper(root, item, found);
}

template<class ItemType>
void TreeType<ItemType>::retreive_helper(TreeNode<ItemType>* ptr, ItemType& item, bool& found) const {

    if (ptr == NULL) {

        found = false;
    }
    else if (item < ptr->info) {

        retreive_helper(ptr->left, item, found);
    }
    else if (item > ptr->info) {

        retreive_helper(ptr->right, item, found);
    }
    else {

        item = ptr->info;
        found = true;
    }
}



template<class ItemType>
void TreeType<ItemType>::print_tree(ofstream& outFile) const {

    print_helper(root, outFile);
}

template<class ItemType>
void TreeType<ItemType>::print_helper(TreeNode<ItemType>* ptr, ofstream& outFile) const {

    if (ptr != NULL) {

        print_helper(ptr->left, outFile);
        outFile << ptr->info << endl;
        print_helper(ptr->right, outFile);
    }
}


template<class ItemType>
TreeType<ItemType>::~TreeType() {

    destroy_helper(root);
}

template<class ItemType>
void TreeType<ItemType>::destroy_helper(TreeNode<ItemType>* ptr) {

    if (ptr != NULL) {

        destroy_helper(ptr->left);
        destroy_helper(ptr->right);
        delete ptr;
    }
}


int main() {
    const int SIZE = 6;
    string arr[SIZE] = { "Dubai", "London", "NewYork", "Oman", "Pakistan", "Qatar" };
    ofstream outFile("sorted_strings.txt");

    TreeType<string> tree;
    for (int i = 0; i < SIZE; ++i) {

        tree.insert_item(arr[i]);
    }

    tree.print_tree(outFile);

    outFile.close();

    cout << "Strings sorted :)) Check file for results." << endl;
    return 0;
}
