#include <iostream>
using namespace std;

struct Node {

    int info;
    Node* next;
};

class LinkedString {

private:

    Node* ptr;

public:
   
    LinkedString() {

        ptr = nullptr; 
    }

  
    ~LinkedString() {

        Node* temp;

        while (ptr != nullptr) {

            temp = ptr;
            ptr = ptr->next;
            delete temp;

        }
    }

    void make_string(int l) {

        if (l <= 0) {

            return;
        }

        cout << "Enter " << l << " values: ";

        for (int i = 0; i < l; i++) {

            int val;
            cin >> val;
            Node* newNode = new Node;
            newNode->info = val;
            newNode->next = ptr;
            ptr = newNode;

        }
    }


    void display_string() {

        Node* temp = ptr;

        while (temp != nullptr) {

            cout << temp->info << " -> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }


    void remove_first() {

        if (ptr == nullptr) {

            return;
        }

        Node* temp = ptr;
        ptr = ptr->next;
        delete temp;

    }

    void remove_last() {

        if (ptr == nullptr) {

            return;
        }

        if (ptr->next == nullptr) {

            delete ptr;
            ptr = nullptr;
            return;
        }

        Node* temp = ptr;

        while (temp->next->next != nullptr) {

            temp = temp->next;
        }

        delete temp->next;

        temp->next = nullptr;
    }


    void remove(int k) {

        if (ptr == nullptr) {
            return;
        }

        if (ptr->info == k) {
            remove_first();
            return;
        }

        Node* temp = ptr;

        while (temp->next != nullptr && temp->next->info != k) {
            temp = temp->next;
        }

        if (temp->next == nullptr) {
            return;
        }

        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }
};


int main() {

    LinkedString list;

    int len;
    cout << "\n>> Inputlength of linked list: ";
    cin >> len;
    list.make_string(len);

    cout << "\n>> Displalying original list: ";

    list.display_string();

    cout << "\n>> Removing first element of list \n";

    list.remove_first();

    list.display_string();

    cout << "\n>> Removing last element of list \n";

    list.remove_last();

    list.display_string();

    int value_to_delete;

    cout << "\n>> Input value you wish to remove from list:  ";
    cin >> value_to_delete;

    list.remove(value_to_delete);

    list.display_string();

    return 0;
}
