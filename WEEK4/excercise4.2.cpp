#include <iostream>
#include <string>
using namespace std;

template <class ItemType>

class Que {

private:

    int front;
    int rear;
    int maxQue;
    int count;
    ItemType* items;

public:

    Que();                   
    Que(int max);            
    ~Que();                  
    int IsFull() const;
    int IsEmpty() const;
    void Insert(ItemType newItem);
    void Remove(ItemType& item);

};


template <class ItemType>
Que<ItemType>::Que() {
    maxQue = 501;
    front = 0;
    rear = 0;
    count = 0;
    items = new ItemType[maxQue]; 
}

template <class ItemType>
Que<ItemType>::Que(int max) {
    maxQue = max + 1;
    front = 0;
    rear = 0;
    count = 0;
    items = new ItemType[maxQue];  
}


template <class ItemType>
Que<ItemType>::~Que() {
    delete[] items;  
}


template <class ItemType>
int Que<ItemType>::IsEmpty() const {
    return (count == 0);
}


template <class ItemType>
int Que<ItemType>::IsFull() const {
    return (count == maxQue);
}


template <class ItemType>
void Que<ItemType>::Insert(ItemType newItem) {
    if (IsFull()) {
        cout << "Over Flow" << endl;
    }
    else {
        items[rear] = newItem;
        rear = (rear + 1) % maxQue;  
        ++count;
    }
}


template <class ItemType>
void Que<ItemType>::Remove(ItemType& item) {
    if (IsEmpty()) {
        cout << "Under Flow" << endl;
    }
    else {
        item = items[front];
        front = (front + 1) % maxQue;  
        --count;
    }
}

int main() {
    Que<string> q(10);  

    string names[10] = { "Sana", "Zayed", "Hareem", "Ahsan", "Nimra", "Maira", "Saad", "Kahsaf", "Iqra", "Maham" };


    cout << ">> Inserting 10 names into the queue " << endl;
    for (int i = 0; i < 10; i++) {
        q.Insert(names[i]);
    }


    cout << "\n>> Removing and Printing the inserted names from the queue: " << endl;

    cout << endl;

    cout << "    ";

    string removed_name;

    for (int i = 0; i < 10; i++) {
        q.Remove(removed_name);
        cout << removed_name << " |  ";
    }
    cout << endl;

    return 0;
}
