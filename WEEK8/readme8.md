# 🌳 Binary Tree ADT in C++ (Dynamic Node Representation)

This project implements a **Binary Tree Abstract Data Type (ADT)** in C++ using **dynamic node representation**. The design is based on the structure and operations outlined in _Data Structures and Algorithms Handbook_ by **Saima Jawad**.

---

## 📚 Key Concepts

The Binary Tree ADT supports:

- Creating an empty binary tree
- Inserting a root node
- Adding left and right children
- Traversing the tree:
  - Preorder (Root → Left → Right)
  - Inorder (Left → Root → Right)
  - Postorder (Left → Right → Root)

---

## ⚙️ Implementation Overview

Each node is dynamically allocated using the `TreeNode<T>` structure:

struct TreeNode {
    T info;
    TreeNode* left;
    TreeNode* right;
    TreeNode* father;

    TreeNode(T value) : info(value), left(nullptr), right(nullptr), father(nullptr) {}
};

## Tree Diagram used in both Excercises as Sample:

          15
         /  \
       9      17
      / \     / \
     5   3   2   8

