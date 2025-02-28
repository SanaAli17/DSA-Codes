#include <iostream>
using namespace std;

#define maxQue 100
typedef int ItemType;


class Queue {
private:

    ItemType items[maxQue];
    int front, rear, count;

public:

    Queue();
    int IsEmpty();
    int IsFull();
    void Insert(ItemType newItem);
    void Remove(ItemType& item);
};

Queue::Queue() {

    count = 0;
    front = 0;
    rear = 0;

}


int Queue::IsEmpty() {

    return (count == 0);
}


int Queue::IsFull() {

    return (count == maxQue);
}

void Queue::Insert(ItemType newItem) {

    if (IsFull()) {

        cout << "Over Flow :( " << endl;

    }
    else {

        items[rear] = newItem;
        rear = (rear + 1) % maxQue;
        ++count;
    }
}


void Queue::Remove(ItemType& item) {

    if (IsEmpty()) {

        cout << "Under Flow :( " << endl;

    }
    else {

        item = items[front];
        front = (front + 1) % maxQue;
        --count;

    }
}


int main() {

    Queue q1;
    ItemType val;


    cout << ">> Inserting 10 numbers starting from zero into the queue  " << endl;

    for (int i = 0; i < 10; i++) {

        q1.Insert(i);
    }


    cout << "\n>> Removing and Printing the numbers inserted from queue:  " << endl;
    cout << endl;

    cout << "   ";


    for (int i = 0; i < 10; i++) {

        q1.Remove(val);
        cout << val << " ";

    }
    cout << endl;

    return 0;
}
