#include <iostream>
template <class ItemType>

class Stack {

private:
    int top;
    int maxStack;
    ItemType* items;

public:
    Stack();
    Stack(int max);
    ~Stack();

    bool IsEmpty() const;
    bool IsFull() const;
    void Push(ItemType newItem);
    void Pop(ItemType& item);
    ItemType Peek() const;

};


