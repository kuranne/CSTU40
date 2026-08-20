---
type: lecture
title: Introduction to Data Structures & OOP Principles
course_code: CS213
week: 1
tags:
  - data-structure
  - oop
  - abstraction
  - complexity
  - big-o
description: Introduction to Data Structures, Abstract Data Types (ADT), and Object-Oriented Programming principles including Data Abstraction, Encapsulation, Inheritance, and Polymorphism.
---

# 🌲 Introduction to Data Structures & OOP Principles

> [!info] Navigation: [[CSTU40]] > [[Year 2]] > [[Year 2 Semester 1]] > [[CS213]] > [[Introduction to Data Structure]]
> **Related Notes:** [[C++ Programming Language]] \| [[CS213]]

---

## 1. Object-Oriented Programming (OOP) Principles

Object-Oriented Programming (OOP) is the core paradigm used to design and implement robust, reusable data structures. It rests upon four foundational pillars:

```
                  ┌─────────────────────────────────┐
                  │          OOP 4 Pillars          │
                  └─────────────────────────────────┘
                     │         │        │        │
         ┌───────────┘         │        │        └───────────┐
         ▼                     ▼        ▼                    ▼
   1. Abstraction     2. Encapsulation  3. Inheritance  4. Polymorphism
```

### 1.1 Data Abstraction
- **Definition:** The process of hiding complex internal implementation details while exposing only the essential features and public interface to the outside world.
- **Objective:** Reduces conceptual complexity and decouples client code from internal data representations.
- **Conceptual Example:**
  Consider a real-world `Student` entity containing extensive personal data:
  ```
  Student (Full real-world properties):
      - DNA Sequence
      - Student ID
      - Full Name
      - Favorite Food
      - Blood Type
  ```
  When modeling a class for a university registration system, we abstract only the relevant properties and behaviors:
  ```cpp
  class Student {
  private:
      std::string studentId;
      std::string fullName;
      double gpa;
  public:
      void registerCourse(const std::string& courseId);
      double getGPA() const;
  };
  ```

### 1.2 Encapsulation
- **Definition:** The bundling of data attributes and the methods that operate on them into a single unit (class), while restricting direct access from outside via access specifiers (`private`, `protected`, `public`).
- **Benefit:** Protects internal object state from unauthorized modification or invalid state transitions (maintains data invariants) by requiring access through controlled member functions (getters/setters/methods).

### 1.3 Inheritance
- **Definition:** The mechanism by which a new class (derived/child class) inherits attributes and methods from an existing class (base/parent class).
- **Benefit:** Promotes code reusability and establishes hierarchical "is-a" relationships (e.g., `BinarySearchTree` is-a `BinaryTree`).

### 1.4 Polymorphism
- **Definition:** The ability of different objects to respond to the same interface or function call in specialized ways based on their concrete type.
- **Forms:**
  1. **Compile-time Polymorphism (Static Binding):** Function Overloading and Operator Overloading in C++.
  2. **Run-time Polymorphism (Dynamic Binding):** Virtual functions (`virtual`) and Abstract Base Classes (interfaces) resolved via dynamic dispatch tables (vtables).

---

## 2. Data Structures & Abstract Data Types (ADT)

### 2.1 What is a Data Structure?
A **Data Structure** is a specialized format for organizing, storing, processing, and retrieving data efficiently within computer memory.

### 2.2 Abstract Data Type (ADT)
An **ADT** is a mathematical model for data types where the type is defined by its behavior (semantics) from the user's perspective, rather than its concrete implementation:
1. **Values/State:** What data it holds.
2. **Operations:** What operations can be performed on it (e.g., `insert()`, `delete()`, `search()`, `isEmpty()`).
3. *Independent of implementation details, algorithms, or programming languages.*

> **Example:**
> - **ADT Stack:** Defined strictly by LIFO (Last-In, First-Out) semantics with operations `push()`, `pop()`, `top()`, `isEmpty()`.
> - **Concrete Implementation:** Can be realized via an **Array-based Stack** or a **Linked-List-based Stack**.

### 2.3 Classification of Data Structures

```
                       ┌─────────────────────────┐
                       │     Data Structures     │
                       └─────────────────────────┘
                                    │
            ┌───────────────────────┴───────────────────────┐
            ▼                                               ▼
   Linear Data Structures                       Non-Linear Data Structures
   (Sequential elements)                        (Hierarchical or interconnected elements)
   - Arrays / Dynamic Arrays (Vectors)          - Trees (Binary Tree, BST, AVL, Heaps)
   - Linked Lists (Singly, Doubly, Circular)    - Graphs (Directed, Undirected, Weighted)
   - Stacks (LIFO)                              - Hash Tables
   - Queues (FIFO, Deques, Priority Queues)
```

---

## 3. Asymptotic Analysis & Big-O Notation

Evaluating data structures and algorithms requires analyzing two critical resources:
1. **Time Complexity:** The amount of computation time an algorithm takes as a function of the input size ($n$).
2. **Space Complexity:** The amount of extra memory space required as a function of the input size ($n$).

### Common Big-O Complexities (Fastest to Slowest)

| Big-O Notation | Complexity Name | Typical Data Structure / Algorithm Examples |
| :--- | :--- | :--- |
| $O(1)$ | Constant Time | Array index lookup, Stack `push()` / `pop()`, Hash table lookup (Average) |
| $O(\log n)$ | Logarithmic Time | Binary Search on a sorted array, Balanced BST operations (AVL, Red-Black) |
| $O(n)$ | Linear Time | Linear Search, Array/Linked List traversal, finding Min/Max in unsorted array |
| $O(n \log n)$ | Linearithmic Time | Efficient sorting algorithms: Merge Sort, Heap Sort, Quick Sort (Average) |
| $O(n^2)$ | Quadratic Time | Simple sorting algorithms: Bubble Sort, Selection Sort, Insertion Sort, Nested Loops |
| $O(2^n)$ | Exponential Time | Recursive calculation of Fibonacci numbers, Exhaustive subset generation |
| $O(n!)$ | Factorial Time | Traveling Salesperson Problem (Brute Force Permutations) |

---

## 🔗 Related Notes & References
- [[CS213]] — Main Course Index for Data Structure
- [[C++ Programming Language]] — Advanced C++ concepts and implementations
