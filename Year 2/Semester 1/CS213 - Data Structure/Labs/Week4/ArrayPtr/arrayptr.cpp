#include <cstddef>     // for NULL
#include "arrayptr.h"

// ============================================================
//  TODO #1  -- implement maxWithPointer()
//
//  'a' is the ADDRESS of the first of n integers.
//  Return the largest one, using a pointer to walk the array.
//
//  Steps:
//    (a) start with  int best = *a;      // dereference (*)
//    (b) move a pointer forward with  p++  and compare  *p
//        with 'best' until you have seen all n elements.
//
//  Reminder: p++ on an int* moves forward by sizeof(int) bytes,
//            i.e. to the NEXT int, not the next byte.
// ============================================================
int maxWithPointer(const int* a, int n) {
    int best = *a;   // (a) the first element

    // >>> write your code here <<<
    int p = 0;
    while (++p < n) if (*(a + p) > best) best = *(a + p);

    return best;
}

// ============================================================
//  TODO #2  -- implement findFirst()
//
//  Walk the n integers starting at 'a' with a pointer.
//  As soon as you find an element equal to 'target', return the
//  POINTER to it (that is the pointer itself, NOT *pointer).
//  If the loop finishes without a match, return NULL.
//
//  Hint:  int* p = a;   ...   if (*p == target) return p;
// ============================================================
int* findFirst(int* a, int n, int target) {

    // >>> write your code here <<<
    for (int i = 0; i < n; i++) if (*(a + i) == target) return (a + i);

    return NULL;   // not found
}

// ============================================================
//  TODO #3  -- implement myStrLen()
//
//  A C string is an ARRAY OF char that ends with the character
//  '\0' (the null terminator). Its length is the number of
//  characters BEFORE that '\0'.
//
//  Walk the string with a pointer until *p == '\0' and count
//  how many steps you took.
// ============================================================
int myStrLen(const char* s) {
    int len = 0;

    // >>> write your code here <<<
    int i = 0;
    while (*(s + i++) != '\0') len++;

    return len;
}
