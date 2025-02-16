#include <iostream>
#define MAX_ITEMS 100
typedef char ItemType;  

class Stack {

private:

    int top;
    ItemType items[MAX_ITEMS];

public:

    Stack();                 
    int IsEmpty() const;     
    int IsFull() const;      
    void Push(ItemType newItem);  
    void Pop(ItemType& item);     
    ItemType Peek() const;  

};

