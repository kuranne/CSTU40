#include <iostream>
#include "arrayops.h"   // include the header only (never include arrayops.cpp)
using namespace std;

// ============================================================
//  This file is COMPLETE. Do NOT modify it.
//  It is a small GRADER: it calls the functions you write in
//  arrayops.cpp and prints PASS / FAIL for each test case.
//
//  NOTE: your work will be graded again with ANOTHER main.cpp
//  that contains MORE test cases, so do not write code that
//  only makes these particular numbers come out right.
// ============================================================

static int gGot = 0;   // points earned
static int gMax = 0;   // points possible

static void check(const char* what, bool ok, int pts) {
    gMax += pts;
    if (ok) gGot += pts;
    cout << (ok ? "[PASS] " : "[FAIL] ") << what
         << "   (" << (ok ? pts : 0) << "/" << pts << ")" << endl;
}

static bool sameArray(const int a[], const int b[], int n) {
    for (int i = 0; i < n; i++)
        if (a[i] != b[i]) return false;
    return true;
}

int main() {
    cout << "===== Part 1 : Arrays (30 points) =====" << endl;

    // ---------- TODO #1 : sumArray ----------
    {
        int a[5] = {3, -1, 4, 1, -5};
        check("sumArray({3,-1,4,1,-5},5) == 2", sumArray(a, 5) == 2, 6);
        check("sumArray(a,0) == 0            ", sumArray(a, 0) == 0, 4);
    }

    // ---------- TODO #2 : reverseArray ----------
    {
        int a[4] = {1, 2, 3, 4};
        int want[4] = {4, 3, 2, 1};
        reverseArray(a, 4);
        check("reverseArray({1,2,3,4})       ", sameArray(a, want, 4), 5);

        int b[5] = {7, 8, 9, 10, 11};
        int want2[5] = {11, 10, 9, 8, 7};
        reverseArray(b, 5);
        check("reverseArray odd size         ", sameArray(b, want2, 5), 5);
    }

    // ---------- TODO #3 : sumMatrix ----------
    {
        int m[3][MAT_COLS] = { {1, 2, 3, 4},
                               {5, 6, 7, 8},
                               {9, 10, 11, 12} };
        check("sumMatrix(3x4) == 78          ", sumMatrix(m, 3) == 78, 5);

        int m2[1][MAT_COLS] = { {-1, 1, -2, 4} };
        check("sumMatrix(1x4) == 2           ", sumMatrix(m2, 1) == 2, 5);
    }

    cout << "---------------------------------------" << endl;
    cout << "SCORE: " << gGot << " / " << gMax << endl;
    return 0;
}
