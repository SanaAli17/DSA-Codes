#include "stack.h"
#include <cstdlib>
#include <iostream>
using namespace std;


template <class ItemType>
Stack<ItemType>::Stack() {

    maxStack = 500;
    top = -1;
    items = new ItemType[500]; 

}

template <class ItemType>
Stack<ItemType>::Stack(int max) {
    maxStack = max;
    top = -1;
    items = new ItemType[max]; 
}


template <class ItemType>
Stack<ItemType>::~Stack() {
    delete[] items; 
}


template <class ItemType>
bool Stack<ItemType>::IsEmpty() const {
    return (top == -1);
}


template <class ItemType>
bool Stack<ItemType>::IsFull() const {
    return (top == maxStack - 1);
}


template <class ItemType>
void Stack<ItemType>::Push(ItemType newItem) {
    if (IsFull()) {
        cout << "Stack Overflow" << endl;
        exit(1);
    }
    top++;
    items[top] = newItem;
}


template <class ItemType>
void Stack<ItemType>::Pop(ItemType& item) {
    if (IsEmpty()) {
        cout << "Stack Underflow" << endl;
        exit(1);
    }
    item = items[top];
    top--;
}


template <class ItemType>
ItemType Stack<ItemType>::Peek() const {
    if (IsEmpty()) {
        cout << "Stack is empty, cannot peek." << endl;
        exit(1);
    }
    return items[top];
}
