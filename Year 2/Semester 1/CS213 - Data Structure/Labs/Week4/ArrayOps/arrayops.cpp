#include "arrayops.h"

// ============================================================
//  TODO #1  -- implement sumArray()
//
//  Add up the first n elements of the array 'a' and return
//  the result.  Remember: the first element is a[0] and the
//  last one is a[n-1].
//
//  Hint:  int s = 0;
//         for (int i = 0; i < n; i++) ...
//
//  If n <= 0 the loop simply never runs, so 0 is returned.
// ============================================================
int sumArray(const int a[], int n) {
    int s = 0;

    // >>> write your code here <<<
    int i = 0;
    while (i < n) s += a[i++];

    return s;
}

// ============================================================
//  TODO #2  -- implement reverseArray()
//
//  Reverse the first n elements of 'a' IN PLACE, i.e. change
//  the caller's array itself (an array parameter is really the
//  ADDRESS of the first element, so the change is visible to
//  the caller).
//
//  Do NOT create a second array. Swap from both ends instead:
//      a[0] <-> a[n-1], a[1] <-> a[n-2], ...
//  and stop when the two positions meet.
// ============================================================
void reverseArray(int a[], int n) {

    // >>> write your code here <<<
    
    for (int i = 1; i < n; i++) {
        int tmp = a[i];
        a[i] = a[i - 1];
        a[i - 1] = tmp;

        for (int j = i - 1; j > 0; j--) {
            tmp = a[j];
            a[j] = a[j - 1];
            a[j - 1] = tmp;
        }
    }
}

// ============================================================
//  TODO #3  -- implement sumMatrix()
//
//  'm' is a 2-D array with 'rows' rows and MAT_COLS columns.
//  Return the sum of every element.
//
//  Access an element with two subscripts:  m[i][j]
//  You will need TWO nested for-loops.
// ============================================================
int sumMatrix(const int m[][MAT_COLS], int rows) {
    int s = 0;

    // >>> write your code here <<<
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < MAT_COLS; c++) {
            s += m[r][c];
        }
    }

    return s;
}
