---
type: lecture
title: C++ Programming Language for Data Structures
course_code: CS213
week: 1, 2
tags:
  - cpp
  - oop
  - class-design
  - templates
  - operator-overloading
description: Deep dive into modern C++ features for Data Structures, including Classes, Interface vs Implementation, Constructors/Destructors, Operator Overloading, and Templates.
---

# ⚙️ C++ Programming Language for Data Structures

> [!info] Navigation: [[CSTU40]] > [[Year 2]] > [[Year 2 Semester 1]] > [[CS213]] > [[C++ Programming Language]]
> **Related Notes:** [[Introduction to Data Structure]] \| [[CS213]]

---

## 1. C++ as a Superset of C

C++ is built as a superset of the C language. It maintains nearly complete backward compatibility with C syntax and low-level constructs while introducing Object-Oriented Programming (OOP), stronger type safety, exception handling, and generic programming via templates.

---

## 2. Class Declaration & Access Specifiers

In C++, classes define user-defined types with three levels of access control:

| Access Specifier | Visibility and Scope |
| :--- | :--- |
| `private` | Accessible only by member functions and friend classes of the same class (Default for `class`). |
| `protected` | Accessible within the class and by derived (child) classes. |
| `public` | Freely accessible from any external code with an instance of the class. |

```cpp
class Time {
private:
    int hour;    // 0 - 23
    int minute;  // 0 - 59
    int second;  // 0 - 59

public:
    // Constructor with default arguments
    Time(int h = 0, int m = 0, int s = 0);
    
    // Mutators (Setters)
    void setTime(int h, int m, int s);
    
    // Accessors (Getters) with const correctness
    int getHour() const;
    int getMinute() const;
    int getSecond() const;
    
    void printUniversal() const;
};
```

---

## 3. Separating Interface and Implementation (Header vs Source Files)

A fundamental software engineering practice in C++ is separating class declarations (Interface) in header files (`.h` or `.hpp`) from member function definitions (Implementation) in source files (`.cpp`).

```
Time.h (Interface)               Time.cpp (Implementation)
┌────────────────────────┐       ┌────────────────────────┐
│ #ifndef TIME_H         │       │ #include "Time.h"      │
│ #define TIME_H         │       │                        │
│ class Time {           │◄──────│ Time::Time(...) {      │
│    // declarations     │       │    // function logic   │
│ };                     │       │ }                      │
│ #endif                 │       └────────────────────────┘
└────────────────────────┘
```

### 3.1 Include Guards
Use preprocessor directives (`#ifndef`, `#define`, `#endif`) or `#pragma once` to prevent multiple inclusion errors during compilation:

```cpp
#ifndef TIME_H
#define TIME_H

class Time {
    // Declarations
};

#endif // TIME_H
```

### 3.2 Scope Resolution Operator (`::`)
To define a member function outside the class body, use the scope resolution operator `ClassName::MemberName`:

```cpp
#include "Time.h"
#include <iostream>

Time::Time(int h, int m, int s) {
    setTime(h, m, s);
}

void Time::setTime(int h, int m, int s) {
    hour   = (h >= 0 && h < 24) ? h : 0;
    minute = (m >= 0 && m < 60) ? m : 0;
    second = (s >= 0 && s < 60) ? s : 0;
}
```

> **Best Practice:** Avoid `using namespace std;` in header files to prevent namespace pollution. Instead, qualify symbols explicitly (e.g., `std::cout`, `std::string`) or import specific identifiers within implementation files (`using std::cout;`).

---

## 4. Constructors & Destructors

### 4.1 Constructors & Member Initializer Lists
Constructors initialize newly instantiated objects. Utilizing **Member Initializer Lists** directly initializes member variables before the constructor body executes, yielding superior performance for non-primitive types:

```cpp
class Complex {
private:
    float re;
    float im;

public:
    // Member Initializer List Syntax
    Complex(float r = 0.0f, float i = 0.0f) : re(r), im(i) {}
};
```

### 4.2 Destructors (`~ClassName()`)
Destructors execute automatically when an object goes out of scope or is explicitly deleted.
- Named after the class prefixed with a tilde `~`.
- Takes no parameters and returns no values.
- Exactly **one destructor** per class.
- Essential for releasing dynamically allocated heap memory and system resources (RAII: Resource Acquisition Is Initialization).

```cpp
class DynamicArray {
private:
    int* data;
    int size;

public:
    DynamicArray(int s) : size(s), data(new int[s]) {}
    
    // Destructor reclaims heap memory
    ~DynamicArray() {
        delete[] data;
    }
};
```

---

## 5. Operator Overloading

C++ allows redefining the behavior of standard operators (`+`, `-`, `*`, `==`, `<<`, `[]`) for user-defined types:

```cpp
#include <iostream>
#include <cmath>

class Complex {
private:
    float re;
    float im;

public:
    Complex(float x = 0.0f, float y = 0.0f) : re(x), im(y) {}

    // Overload arithmetic + operator
    Complex operator+(const Complex& rhs) const {
        return Complex(re + rhs.re, im + rhs.im);
    }

    // Overload arithmetic * operator
    Complex operator*(const Complex& rhs) const {
        return Complex(re * rhs.re - im * rhs.im, re * rhs.im + im * rhs.re);
    }

    float modulus() const {
        return std::sqrt(re * re + im * im);
    }

    void print() const {
        std::cout << re << " + " << im << "i" << std::endl;
    }
};
```

---

## 6. Generic Data Structures with C++ Templates

Templates enable writing type-independent, reusable data structure classes:

```cpp
template <typename T>
class Node {
public:
    T data;
    Node<T>* next;

    Node(const T& val) : data(val), next(nullptr) {}
};

template <typename T>
class Stack {
private:
    Node<T>* topNode;
    int count;

public:
    Stack() : topNode(nullptr), count(0) {}
    
    void push(const T& val) {
        Node<T>* newNode = new Node<T>(val);
        newNode->next = topNode;
        topNode = newNode;
        count++;
    }

    T pop() {
        if (isEmpty()) throw std::runtime_error("Stack underflow: Stack is empty");
        Node<T>* temp = topNode;
        T val = temp->data;
        topNode = topNode->next;
        delete temp;
        count--;
        return val;
    }

    bool isEmpty() const { return topNode == nullptr; }
    int size() const { return count; }
};
```

---

## 🔗 Related Notes & References
- [[CS213]] — Main Course Index for Data Structure
- [[Introduction to Data Structure]] — Foundational data structures and OOP principles
