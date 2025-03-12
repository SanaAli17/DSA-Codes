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

    Que() {
        maxQue = 501;
        front = 0;
        rear = 0;
        count = 0;
        items = new ItemType[maxQue];
    }

    Que(int max) {
        maxQue = max + 1;
        front = 0;
        rear = 0;
        count = 0;
        items = new ItemType[maxQue];
    }

    ~Que() {
        delete[] items;
    }

    int IsEmpty() const {
        return (count == 0);
    }

    int IsFull() const {
        return (count == maxQue);
    }

    void Insert(ItemType newItem) {
        if (IsFull()) {
            cout << "Over Flow\n";
        }
        else {
            items[rear] = newItem;
            rear = (rear + 1) % maxQue;
            ++count;
        }
    }

    void Remove(ItemType& item) {
        if (IsEmpty()) {
            cout << "Under Flow\n";
        }
        else {
            item = items[front];
            front = (front + 1) % maxQue;
            --count;
        }
    }
};


template <class ItemType>
class PriorityQueueN {

private:

    Que<ItemType>* queues;  
    int numPriorities;       

public:
    
    PriorityQueueN(int n) {

        numPriorities = n;
        queues = new Que<ItemType>[n];
    }


    ~PriorityQueueN() {
        delete[] queues;
    }


    bool IsEmpty() const {

        for (int i = 0; i < numPriorities; i++) {
            if (!queues[i].IsEmpty())
            {
                return false;
            }
        }
        return true;
    }


    void Insert(const ItemType& item, int priority) {

        if (priority < 0 || priority >= numPriorities) {
            cout << "Error: priority out of range!\n";
            return;
        }

        queues[priority].Insert(item);
    }


    void Remove(ItemType& item) {

        for (int i = 0; i < numPriorities; i++) {

            if (!queues[i].IsEmpty()) {

                queues[i].Remove(item);
                return;
            }
        }
        cout << "All queues are empty, nothing to remove!\n";
    }
};


int main() {
    int n;
    cout << "Enter the number of priority levels: ";
    cin >> n;


    PriorityQueueN<string> pq(n);


    pq.Insert("Task at priority 0", 0);

    if (n > 1) {
        pq.Insert("Task at priority 1", 1);
    }

    if (n > 2) {
        pq.Insert("Task at priority 2", 2);

    }

    cout << "\nRemoving items (priority 0 is highest):\n\n";

    while (!pq.IsEmpty()) {
        string removed;
        pq.Remove(removed);

        cout << "Removed: " << removed << endl;
    }

    return 0;
}