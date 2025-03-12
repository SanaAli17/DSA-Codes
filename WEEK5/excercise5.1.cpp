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


template <class ItemType>
class PriorityQueue {

private:

    static const int MAX = 10;  
    Que<ItemType> queues[MAX]; 


public:
    
    bool IsEmpty() const {

        for (int i = 0; i < MAX; i++) {

            if (!queues[i].IsEmpty()) {

                return false;
            }
        }
        return true;
    }


    bool isFull() const {

        for (int i = 0; i < MAX; i++) {

            if (!queues[i].isFull()) {

                return false;
            }
        }
        return true;
    }


    void Insert(const ItemType& item, int priority) {

        if (priority < 0 || priority >= MAX) {

            cout << "OOPS!! priority is out of range :( " << endl;
            return;

        }

        queues[priority].Insert(item);
    }


    void Remove(ItemType& item) {

        for (int i = 0; i < MAX; i++) {

            if (!queues[i].IsEmpty()) {

                queues[i].Remove(item);
                return;

            }
        }
        cout << "Unable to remove, as all priority levels are empty :( " << endl;
    }
};


int main() {

    PriorityQueue<string> p1;


    p1.Insert("Task AA ", 3);
    p1.Insert("Task BB ", 1);  
    p1.Insert("Task CC ", 0);
    p1.Insert("Task DD ", 2);  
    p1.Insert("Task EE ", 5);  

    cout << "\n>> Removing items of highest priority first: \n\n";

    while (!p1.IsEmpty()) {

        string removed_item;

        p1.Remove(removed_item);

        cout << "   Removed: " << removed_item << endl;

    }

    cout << "\n>> Priority Queue is now empty." << endl;

    return 0;
}
