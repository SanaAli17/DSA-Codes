# Stack ADT Implementation Using Dynamic Array and Class Template

## Overview
This project implements a *Stack Abstract Data Type (ADT)* using *dynamic memory allocation* and *C++ class templates*. The implementation supports:

- *Dynamic memory allocation* using pointers.
- *Templates* to allow usage with multiple data types.
- *Basic stack operations* including:
  - IsEmpty() - Check if the stack is empty.
  - IsFull() - Check if the stack is full.
  - Push(ItemType newItem) - Insert an element onto the stack.
  - Pop(ItemType& item) - Remove and return the top element.
  - Peek() - Return the top element without removing it.

## Files Included

### 1. stack.h (Class Specification File)
Defines the *generic template-based stack class*:
- Default and parameterized constructors
- Destructor
- Stack operations (Push, Pop, IsEmpty, IsFull)
- Private dynamic memory handling

### 2. stack.cpp (Class Template Implementation)
Implements the *stack operations* using dynamic arrays:
- Dynamically allocates memory for the stack
- Implements the push/pop operations
- Handles stack overflow/underflow conditions
- Implements a destructor for memory cleanup

### 3. driver.cpp (Driver Program)
Demonstrates the usage of the *stack template*:
- Creates stack instances for int and float
- Pushes elements onto the stack
- Pops and prints the stack elements

## Exercise 2.2
### Problems to Solve Using the Stack:
1. *Validity of a Parenthesized Expression*
   - Check whether a given fully parenthesized expression is valid.

2. *Infix to Postfix Conversion*
   - Convert a valid infix expression into postfix notation.
   - The input consists of *single-letter operands* and *operators (+, -, *, /)*.

3. *Postfix Evaluation*
   - Evaluate a postfix expression and display the result.