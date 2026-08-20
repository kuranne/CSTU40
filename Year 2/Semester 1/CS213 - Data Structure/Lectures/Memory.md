---
type: lecture
title: Memory Management & Layout in C and C++
course_code: CS213
week: 3
tags:
  - data-structures
  - memory-management
  - dynamic-allocation
  - pointers
  - c-cpp
description: Detailed study of runtime program memory layout (Stack, Heap, Data, Text segments), dynamic memory allocation in C (malloc, calloc, realloc, free) vs C++ (new, delete), and memory safety best practices.
---

# 🧠 Memory Management & Layout in C and C++

> [!info] Navigation: [[CSTU40]] > [[Year 2]] > [[Year 2 Semester 1]] > [[CS213]] > [[Memory]]
> **Prerequisites & Related Notes:** [[CS102]] \| [[Introduction to Data Structure]] \| [[C++ Programming Language]] \| [[CS213]]

---

## 1. Process Memory Layout (Runtime Memory Architecture)

When a compiled C/C++ program executes, the operating system assigns it a virtual address space partitioned into distinct memory segments:

```
 High Memory Addresses (0xFFFFFFFF / 0x7FFFFFFFFFFF)
 ┌────────────────────────────────────────────────────────┐
 │                   Stack Segment                        │  ▼ Grows downward
 │   (Local variables, function stack frames, ret addrs)  │  (High -> Low)
 ├────────────────────────────────────────────────────────┤
 │                          ▲                             │
 │                          │                             │
 │                  Unallocated Memory                    │
 │                          │                             │
 │                          ▼                             │
 ├────────────────────────────────────────────────────────┤
 │                   Heap Segment                         │  ▲ Grows upward
 │   (Dynamic memory allocated via malloc/new at runtime) │  (Low -> High)
 ├────────────────────────────────────────────────────────┤
 │             BSS Segment (Uninitialized Data)           │
 │   (Static and global variables initialized to zero)    │
 ├────────────────────────────────────────────────────────┤
 │            Data Segment (Initialized Data)             │
 │   (Explicitly initialized global & static variables)   │
 ├────────────────────────────────────────────────────────┤
 │                   Text / Code Segment                  │
 │   (Read-only compiled machine code instructions)       │
 └────────────────────────────────────────────────────────┘
 Low Memory Addresses (0x00000000)
```

| Memory Segment | Lifetime | Access Speed | Allocation Mechanism | Typical Contents |
| :--- | :--- | :--- | :--- | :--- |
| **Text (Code)** | Program duration | Extremely Fast | Static (Load time) | Read-only machine instructions. |
| **Data (Initialized)** | Program duration | Fast | Static (Load time) | Global variables (e.g., `int count = 10;`), static variables. |
| **BSS (Uninitialized)**| Program duration | Fast | Static (Zeroed out at start) | Global/static variables without explicit initializers. |
| **Heap** | Manual (`malloc`/`free` or `new`/`delete`) | Moderate (Requires OS bookkeeping) | Dynamic at runtime | Dynamically sized arrays, linked nodes, trees. |
| **Stack** | Scope duration (Automatic) | Extremely Fast (SP register shift) | Automatic per function call | Local variables, function parameters, return pointers. |

---

## 2. Dynamic Memory Allocation in C

In standard C (via `<stdlib.h>`), memory must be requested explicitly from the Heap and manually released back to the OS:

### 2.1 The Core C Allocation Functions

1. **`malloc(size_t size)`**: Allocates `size` uninitialized bytes from heap. Returns a generic `void*` pointer (or `NULL` on allocation failure).
   ```c
   int* arr = (int*)malloc(100 * sizeof(int));
   if (arr == NULL) {
       perror("Memory allocation failed");
       exit(EXIT_FAILURE);
   }
   ```

2. **`calloc(size_t num, size_t size)`**: Allocates memory for an array of `num` elements of `size` bytes each, **initializing all bits to zero**.
   ```c
   int* zeroed_arr = (int*)calloc(100, sizeof(int));
   ```

3. **`realloc(void* ptr, size_t new_size)`**: Resizes an existing heap block. It may expand the block in place or allocate a new memory block, copy the old data, free the old block, and return the new address.
   ```c
   int* temp = (int*)realloc(arr, 200 * sizeof(int));
   if (temp != NULL) {
       arr = temp;
   } else {
       // Handle reallocation failure (original 'arr' remains intact)
   }
   ```

4. **`free(void* ptr)`**: Deallocates the allocated memory block back to the heap.
   ```c
   free(arr);
   arr = NULL; // Prevent dangling pointer
   ```

---

## 3. Dynamic Memory Allocation in Modern C++

C++ provides type-safe operators (`new` and `delete`) that not only allocate memory but also execute class constructors and destructors automatically.

```
                  ┌─────────────────────────────────────────┐
                  │    Memory Allocation Paradigm Shift     │
                  └─────────────────────────────────────────┘
                                       │
            ┌──────────────────────────┴──────────────────────────┐
            ▼                                                     ▼
    C Paradigm (malloc / free)                            C++ Paradigm (new / delete)
    - Allocates raw bytes only                            - Allocates typed memory
    - Does NOT call constructors                          - Automatically invokes constructors
    - Requires manual sizeof() calculation                - Type-safe, calculates size implicitly
    - Returns void* (requires cast)                       - Returns typed pointer (T*)
    - free() does NOT call destructors                    - delete automatically invokes destructors
```

### 3.1 Syntax Comparison

```cpp
// Single Object Allocation
Time* t1 = new Time(10, 30, 0); // Allocates memory & calls Time constructor
delete t1;                      // Calls Time destructor & frees memory
t1 = nullptr;

// Array Allocation
int* buffer = new int[50];      // Allocates array of 50 integers
delete[] buffer;                // Note: MUST use delete[] for arrays
buffer = nullptr;
```

### 3.2 RAII & Modern Smart Pointers (C++11/C++14/C++17)
To eliminate manual memory tracking and prevent memory leaks, modern C++ adheres to **RAII (Resource Acquisition Is Initialization)** using Smart Pointers from `<memory>`:

- **`std::unique_ptr<T>`**: Exclusive ownership. Automatically frees the object when the pointer goes out of scope (Zero runtime overhead).
  ```cpp
  #include <memory>
  std::unique_ptr<Time> t = std::make_unique<Time>(8, 0, 0);
  // Automatically deleted when 't' exits scope
  ```
- **`std::shared_ptr<T>`**: Shared reference-counted ownership. Memory is freed when the last reference is destroyed.

---

## 4. Common Memory Pitfalls & Debugging

| Pitfall | Description | Consequence | Prevention / Solution |
| :--- | :--- | :--- | :--- |
| **Memory Leak** | Heap memory allocated without a corresponding `free()` or `delete`. | Process memory grows continuously, degrading system performance. | Adopt RAII / Smart Pointers; pair every `malloc` with `free`. |
| **Dangling Pointer** | A pointer referencing a memory address that has already been deallocated. | Undefined behavior, random crashes, or silent data corruption. | Set pointers to `NULL` / `nullptr` immediately after freeing. |
| **Double Free** | Calling `free()` or `delete` twice on the exact same memory pointer. | Heap metadata corruption; severe security vulnerability. | Zero out freed pointers immediately. |
| **Buffer Overflow** | Writing data beyond the allocated boundaries of an array or heap block. | Memory corruption, Segmentation Fault (`SIGSEGV`), exploit vectors. | Validate bounds checks (`size_t` indices) and use `std::vector`. |

---

## 🔗 Related Notes & References
- [[CS213]] — Main Course Index for Data Structure
- [[CS102]] — Foundational C programming and pointers
- [[C++ Programming Language]] — Classes, constructors, and RAII in C++
- [[Introduction to Data Structure]] — Abstract Data Types and memory complexity
