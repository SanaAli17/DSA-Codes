#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;

template<class ItemType>

class List {

protected:

    struct node {

        ItemType info;
        struct node* next;

    };

    typedef struct node* NODEPTR;
    NODEPTR listptr;

public:

    List();
    ~List();
    bool emptyList();
    void insertAfter(ItemType oldvalue, ItemType newvalue);
    void deleteItem(ItemType oldvalue);
    void push(ItemType newvalue);
    ItemType pop();

};


template<class ItemType>
List<ItemType>::List() {
    listptr = nullptr;
}

template<class ItemType>
List<ItemType>::~List() {

    NODEPTR p, q;

    while (listptr) {
        p = listptr;
        listptr = listptr->next;
        delete p;
    }
}


template<class ItemType>
bool List<ItemType>::emptyList() {
    return (listptr == nullptr);
}


template<class ItemType>
void List<ItemType>::insertAfter(ItemType oldvalue, ItemType newvalue) {

    NODEPTR p, q;
    
    for (p = listptr; p != nullptr && p->info != oldvalue; p = p->next);

    if (p == nullptr) {
        cout << "ERROR: value sought is not in the list :( " << endl;
        return;
    }

    q = new node;
    q->info = newvalue;
    q->next = p->next;
    p->next = q;
}


template<class ItemType>
void List<ItemType>::push(ItemType newvalue) {

    NODEPTR p;
    p = new node;
    p->info = newvalue;
    p->next = listptr;
    listptr = p;
}


template<class ItemType>
void List<ItemType>::deleteItem(ItemType oldvalue) {

    NODEPTR p, q = nullptr;

    for (p = listptr; p != nullptr && p->info != oldvalue; q = p, p = p->next);

    if (p == nullptr) {
        cout << "ERROR: value sought is not in the list :( " << endl;
        return;
    }

    if (q == nullptr) {
        listptr = p->next;
    }
    else {
        q->next = p->next;
    }
    delete p;
}


template<class ItemType>
ItemType List<ItemType>::pop() {

    if (emptyList()) {
        cout << "ERROR: the list is empty." << endl;
        exit(1);
    }

    NODEPTR p = listptr;
    ItemType x = p->info;
    listptr = p->next;
    delete p;
    return x;
}


int main() {

    List<int> li;

    li.push(11);
    li.push(50);
    li.push(30);

    cout << "\n>> Popped: " << li.pop() << endl; 

    li.insertAfter(50, 14);
    li.deleteItem(30);

    cout << "\n>> Popped: " <<li.pop() << endl; 

    
    List<char> ls;
    string input_string = "COOL";

    for (char c : input_string) {

        ls.push(c);

    }

    cout << "\n>> Reversed string is: ";

    while (!ls.emptyList()) {

        cout << ls.pop();
    }
    cout << endl;

    return 0;
}
