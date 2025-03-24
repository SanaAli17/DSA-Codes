
#include <iostream>
#include <conio.h>
using namespace std;


template <class T>
class double_Linked {

    struct node {

        T data;
        node* prev;
        node* next;

        node(T t, node* p = NULL, node* n = NULL) : data(t), prev(p), next(n) {}

    };

    node* head;
    node* tail;

public:

    double_Linked() : head(NULL), tail(NULL) {}

    template<int N>
    double_Linked(T(&arr)[N]) : head(NULL), tail(NULL) {

        for (int i = 0; i < N; ++i)
            push_back(arr[i]);
    }

    bool empty() const { 

        return (!head || !tail); 
    }

    operator bool() const {

        return !empty();
    }

    void push_back(T);

    void push_front(T);

    T pop_back();

    T pop_front();

    ~double_Linked() {

        while (head) {

            node* temp(head);
            head = head->next;
            delete temp;

        }
    }
};


template <class T>
void double_Linked<T>::push_back(T data) {

    tail = new node(data, tail, NULL);

    if (tail->prev) {

        tail->prev->next = tail;
    }

    if (empty()) {

        head = tail;
    }
}


template <class T>
void double_Linked<T>::push_front(T data) {

    head = new node(data, NULL, head);

    if (head->next) {

        head->next->prev = head;
    }

    if (empty()) {

        tail = head;
    }
}


template <class T>
T double_Linked<T>::pop_back() {

    if (empty())
        throw("double_Linked : list empty");

    node* temp(tail);
    T data(tail->data);
    tail = tail->prev;

    if (tail) {

        tail->next = NULL;
    }

    else {

        head = NULL;
    }

    delete temp;
    return data;
}


template <class T>
T double_Linked<T>::pop_front() {

    if (empty())
        throw("double_Linked : list empty");

    node* temp(head);
    T data(head->data);
    head = head->next;

    if (head) {

        head->prev = NULL;
    }

    else {
        tail = NULL;
    }

    delete temp;
    return data;
}

int main() 
{

        long arr[] = { 8000000, 30000000, 10000000, 44400000, 17880000 };

        double_Linked<long> dlist(arr);

        dlist.push_back(1780000);
        dlist.push_front(8000000);

        cout << "\n>> Elements removed from back: ";

        while (dlist)
            cout << dlist.pop_back() << " ";

        cout << endl;

        return 0;
    }