 # Graph Traversal and Shortest Path Algorithms

It contains implementations of fundamental graph traversal algorithms — **Depth-First Search (DFS)** and **Breadth-First Search (BFS)** — along with **Dijkstra's Shortest Path Algorithm**, as outlined in the exercises.

## 📘 Algorithms Implemented

### 1. Depth-First Search (DFS)
- Traverses the graph by visiting a vertex, then recursively exploring each unvisited adjacent vertex.
- Utilizes a recursive approach with a `visited[]` array.
- Pseudocode extracted from the book (Page 68).

### 2. Breadth-First Search (BFS)
- Traverses the graph level-by-level using a queue.
- Each vertex is enqueued when first discovered and dequeued when processed.
- Also uses a `visited[]` array.
- Pseudocode provided on Page 69.

### 3. Dijkstra’s Shortest Path Algorithm
- Calculates the shortest path from a starting vertex to all other vertices in a weighted graph.
- Exercise 11.2 instructs its implementation.
- Uses a priority queue (min-heap) and maintains distance estimates.

---



