# 🧠 Graph Representations in C++

## 📚 Overview

This project demonstrates two fundamental ways of implementing graphs in C++:

1. **Adjacency List Representation** using linked structures (custom classes).
2. **Adjacency Matrix Representation** using a 2D array.

Each method has its own benefits and trade-offs, and this project showcases both for educational purposes.

---

## 🧩 Concepts Used

### ✅ Graph Theory Basics
- A **graph** is a set of vertices (nodes) connected by edges.
- Graphs can be **directed** or **undirected**, and edges may have **weights** (as in this project).
- Common graph operations include:
  - Adding/removing vertices
  - Adding/removing edges
  - Checking adjacency
  - Traversing or printing the graph

---

## 📎 1. Adjacency List Representation

### Structure:
- Each **vertex** maintains a linked list of **edges**.
- An **edge** contains a pointer to the destination vertex, weight, and a link to the next edge.
- The graph maintains a linked list of all vertices.

---

## 📎 2. Adjacency Matrix Representation

### Structure:
- A fixed-size 2D array (`MAXVER x MAXVER`) where each cell represents an edge.
- Each cell holds a boolean for adjacency and an integer for the edge weight.


## 🔁 Comparison

| Feature                 | Adjacency List            | Adjacency Matrix            |
|------------------------|---------------------------|-----------------------------|
| Memory Efficiency      | Good for sparse graphs    | Consumes more memory        |
| Edge Lookup Time       | Slower (linked list)      | Faster (constant time)      |
| Dynamic Vertex Support | Easier to manage          | Hard with fixed-size arrays |
| Implementation Style   | Pointer-based structures  | Array-based representation  |

---

