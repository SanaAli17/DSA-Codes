# 🔍 Search Algorithms in C++

This repository contains C++ implementations of two fundamental search algorithms:

- ✅ **Sequential Search (Linear Search)**
- ✅ **Binary Search**

---
## 🧠 Algorithm Descriptions

### 🔹 Sequential (Linear) Search

Sequential Search (or Linear Search) is the simplest searching algorithm. It goes through each element in the array one by one and checks if it matches the target value.

- **How it works:**  
  Starts from the first element and compares each one until it finds a match or reaches the end of the array.

- **Best Case Time Complexity:** O(1) – when the target is the first element  
- **Average Case Time Complexity:** O(n)  
- **Worst Case Time Complexity:** O(n) – when the target is not present  
- **Space Complexity:** O(1)

- **Use Case:**  
  Useful for small or unsorted datasets where performance is not critical.

---

### 🔹 Binary Search

Binary Search is a highly efficient algorithm for finding an element in a **sorted** array. It repeatedly divides the search interval in half.

- **How it works:**  
  Compare the target value with the middle element.  
  If they’re equal, you found it.  
  If the target is smaller, repeat on the left half.  
  If it’s larger, repeat on the right half.

- **Best Case Time Complexity:** O(1) – when the middle element is the target  
- **Average Case Time Complexity:** O(log n)  
- **Worst Case Time Complexity:** O(log n)  
- **Space Complexity:**  
  - O(1) for iterative version  
  - O(log n) for recursive version

- **Use Case:**  
  Ideal for large, sorted datasets where performance is crucial.

