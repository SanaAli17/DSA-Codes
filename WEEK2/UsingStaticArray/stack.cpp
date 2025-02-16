#include "stack.h"
#include <cstdlib>
#include <iostream>
using namespace std;

Stack::Stack() {

    top = -1;

}

int Stack::IsEmpty() const {

    return (top == -1);

}

int Stack::IsFull() const {

    return (top == MAX_ITEMS - 1);

}

void Stack::Push(ItemType newItem) {

    if (IsFull()) {

        cout << "oops! stack overflow " << endl;
        exit(1);

    }

    top++;

    items[top] = newItem;
}

void Stack::Pop(ItemType& item) {

    if (IsEmpty()) {

        cout << "oops! stack underflow" << endl;
        exit(1);

    }

    item = items[top];

    top--;
}

ItemType Stack::Peek() const {

    if (IsEmpty()) {

        cout << "oops! Stack is empty. Cannot peek :( " << endl;
        exit(1);

    }

    return items[top];
}
