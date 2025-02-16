# Stack ADT Implementation

## Overview
This project implements a *Stack Abstract Data Type (ADT)* using a *static array* in C++. The stack supports basic operations such as:

- *Initialize()* - Sets stack to an empty state.
- *IsEmpty()* - Determines whether the stack is currently empty.
- *IsFull()* - Determines whether the stack is currently full.
- *Push(ItemType newItem)* - Adds a new item to the top of the stack.
- *Pop(ItemType& item)* - Removes the item at the top of the stack and retrieves it.
- *Peek()* - Returns the value at the top of the stack without removing it (*to be implemented in Exercise 2.1*).

## Files Included

### 1. stack.h (Class Specification File)
Defines the Stack class and its member functions:
- Constructor
- IsEmpty()
- IsFull()
- Push(ItemType newItem)
- Pop(ItemType& item)
- Peek() (to be implemented)

### 2. stack.cpp (Implementation File)
Implements the Stack class functions, including:
- Stack initialization (top = -1)
- Checking for empty or full conditions
- Pushing and popping elements with overflow/underflow checks

### 3. driver.cpp (Driver File)
Contains the main() function to test the stack implementation by:
- Pushing integers onto the stack
- Popping and displaying the stack elements

## Exercise 2.1
### Tasks:
1. **Add a function Peek()** to return the value at the top of the stack *without removing it*.
2. *Use the Stack class* to write a function that *reverses a string*.