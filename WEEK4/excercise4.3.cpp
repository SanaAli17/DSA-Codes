#include <iostream>
using namespace std;
#define MAX 10

class Deque {

private:

    int array[MAX];
    int front, rear;

public:

    Deque() {

        front = -1;
        rear = -1;
    }

    bool isFull() {

        return ((front == 0 && rear == MAX - 1) || (front == rear + 1));
    }

    bool isEmpty() {

        return (front == -1);
    }

        void insertAtFront(int value) {

        if (isFull()) {

            cout << "OOPS!!! Deque is full :( " << endl;
            return;
        }
        if (front == -1) { 

            front = rear = 0;
        }
        else if (front == 0) { 

            front = MAX - 1;
        }
        else {
            front--;
        }
        array[front] = value;
        cout << "\n// Inserted " << value << " at front." << endl;
    }

    void insertAtRear(int value) {

        if (isFull()) {

            cout << "OOPS!!! Deque is full :( " << endl;
            return;
        }
        if (rear == -1) { 

            rear = front = 0;
        }
        else if (rear == MAX - 1) { 

            rear = 0;
        }
        else {
            rear++;
        }

        array[rear] = value;

        cout << "\n// Inserted " << value << " at rear." << endl;
    }



    void removeFromFront() {

        if (isEmpty()) {

            cout << "OOPS!!! Deque is empty :( " << endl;
            return;
        }
        cout << "\n// Removed " << array[front] << " from front." << endl;

        if (front == rear) { 

            front = rear = -1;
        }
        else if (front == MAX - 1) { 
            front = 0;
        }
        else {
            front++;
        }
    }


    void removeFromRear() {

        if (isEmpty()) {

            cout << "OOPS!!! Deque is empty :( " << endl;
            return;
        }
        cout << "\n// Removed " << array[rear] << " from rear." << endl;

        if (front == rear) { 

            front = rear = -1;
        }
        else if (rear == 0) {

            rear = MAX - 1;
        }
        else {

            rear--;
        }
    }

    void display() {

        if (isEmpty()) {

            cout << "OOPS!!! Deque is empty :( " << endl;
            return;
        }
        cout << endl;

        cout << "\n>> Currently the Elements in Deque Are: ";

        cout << endl;
        cout << endl;

        int i = front;
        while (true) {
            cout << "   "<< array[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % MAX; 
        }

        cout << endl;
    }
};

int main() {
    Deque dq1;

    dq1.insertAtRear(11);
    dq1.insertAtRear(40);
    dq1.insertAtFront(23);
    dq1.insertAtFront(13);
    dq1.insertAtRear(18);

    dq1.display();

    dq1.removeFromFront();
    dq1.display();

    dq1.removeFromRear();
    dq1.display();

    dq1.removeFromRear();
    dq1.display();

    return 0;
}
