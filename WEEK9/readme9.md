# 🌳 Binary Search Tree in C++ — String Sorting Example

## 📘 Overview

This project implements a **Binary Search Tree (BST)** using **C++ templates**, designed to store and sort data efficiently. The current example uses an array of strings and outputs them in sorted (lexicographical) order to a file.

---

## 🔑 Concepts Used

### ✅ Templates
- Generic programming approach using `template<class ItemType>` to support different data types without rewriting the code.

### ✅ Binary Search Tree (BST)
- Each node contains a value.
- Left child nodes are less than the parent node.
- Right child nodes are greater than the parent node.
- No duplicate values are inserted.

### ✅ Recursion
- Core operations like insert, retrieve, traverse, and destroy are implemented recursively:
  - `insert_helper`
  - `retreive_helper`
  - `print_helper`
  - `destroy_helper`

### ✅ File I/O
- Sorted data is written to `sorted_strings.txt` using `ofstream`.

### ✅ Memory Management
- Nodes are dynamically allocated with `new`.
- `is_full()` checks for memory allocation failure using a `try-catch` block.
- Destructor properly deallocates all nodes to avoid memory leaks.

### ✅ OOP Principles
- Encapsulation of logic inside `TreeType` class.
- Abstraction through private helper functions.
- Separation of concerns between the public API and internal implementation.

---

