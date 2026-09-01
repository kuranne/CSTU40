#ifndef ARRAYPTR_H
#define ARRAYPTR_H

// ============================================================
//  Lab 3 - Part 2 : Arrays and Pointers
//  Declarations only.  (This file is COMPLETE. Do NOT modify.)
//
//  RULE FOR THIS PART:
//  Inside arrayptr.cpp you must walk the arrays with a POINTER.
//  The subscript operator []  is NOT allowed in arrayptr.cpp.
//  Use  *p , p++ , *(p + i) , p != end   instead.
// ============================================================

// Returns the largest of the n integers that start at address a.
// You may assume n >= 1.
//    {4,9,2,9,1}, n=5   ->   9
int maxWithPointer(const int* a, int n);

// Searches the n integers that start at address a and returns
// a POINTER to the FIRST element whose value is target.
// Returns NULL when no element matches.
//    a = {10,20,30,20}, target = 20   ->   &a[1]
int* findFirst(int* a, int n, int target);

// Returns the length of the C string s, i.e. how many characters
// come before the terminating '\0'.  Do NOT call strlen().
//    "Hello"  ->  5        ""  ->  0
int myStrLen(const char* s);

#endif // ARRAYPTR_H
