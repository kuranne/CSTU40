---
type: lecture
description:
---
#Week3 
# Memory

## Memory Usage of Program

During program is executing, there will use Memory like this:
- **Code:** instruction and compiled program
- **Global:** static or global Variable
- **Heap:** Dynamic Allocation
- **Stack:** Local variable

## Dynamic Memory Allocation

Commonly, program can't know how size of memory will be use. In C, we mostly use static array size like `array[100]`, so if want more than 100 index, there is the way to use Dynamic Memory Allocation.

In C, we use `int *a = (*int)malloc(size_t size,size_t sizeof(int))` to allocate memory in heap memory, then we use `int *b = realloc(void *ptr, size_t newsize)` to reallocate memory in heap. Finally, use `free(void *ptr)` to clear out of memory.

In C++, we use new to allocate same like in C, but they didn't want reallocate to decrease or increase the size. And use delete to destroy them.