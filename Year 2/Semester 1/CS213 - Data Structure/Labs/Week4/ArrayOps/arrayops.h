#ifndef ARRAYOPS_H
#define ARRAYOPS_H

// ============================================================
//  Lab 3 - Part 1 : Arrays
//  Declarations only.  (This file is COMPLETE. Do NOT modify.)
// ============================================================

// Number of columns of every 2-D array used in this part.
// A function that receives a 2-D array must know every dimension
// except the first one   ->   int m[][MAT_COLS]
const int MAT_COLS = 4;

// Returns the sum of the first n elements of a.
// If n <= 0 the result is 0.
//    {3,-1,4,1,-5}, n=5   ->   2
int sumArray(const int a[], int n);

// Reverses the first n elements of a IN PLACE
// (the caller's array itself must change).
//    {1,2,3,4}   ->   {4,3,2,1}
void reverseArray(int a[], int n);

// Returns the sum of every element of a rows x MAT_COLS matrix.
//    {{1,2,3,4},{5,6,7,8}}, rows=2   ->   36
int sumMatrix(const int m[][MAT_COLS], int rows);

#endif // ARRAYOPS_H
