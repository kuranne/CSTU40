#include <iostream>
#include <cstddef>
#include "arrayptr.h"   // include the header only (never include arrayptr.cpp)
using namespace std;

// ============================================================
//  This file is COMPLETE. Do NOT modify it.
//  Small GRADER for Part 2.
//
//  NOTE: your work will be graded again with ANOTHER main.cpp
//  that contains MORE test cases.
// ============================================================

static int gGot = 0;
static int gMax = 0;

static void check(const char* what, bool ok, int pts) {
    gMax += pts;
    if (ok) gGot += pts;
    cout << (ok ? "[PASS] " : "[FAIL] ") << what
         << "   (" << (ok ? pts : 0) << "/" << pts << ")" << endl;
}

int main() {
    cout << "===== Part 2 : Arrays and Pointers (30 points) =====" << endl;

    // ---------- TODO #1 : maxWithPointer ----------
    {
        const int a[5] = {4, 9, 2, 9, 1};
        check("maxWithPointer({4,9,2,9,1},5) == 9 ", maxWithPointer(a, 5) == 9, 5);

        const int b[3] = {-5, -2, -9};
        check("maxWithPointer(all negative) == -2 ", maxWithPointer(b, 3) == -2, 5);
    }

    // ---------- TODO #2 : findFirst ----------
    {
        int a[5] = {10, 20, 30, 20, 40};
        // must return the address of the FIRST 20, which is &a[1]
        check("findFirst(a,5,20) == &a[1]         ", findFirst(a, 5, 20) == &a[1], 5);
        check("findFirst(a,5,99) == NULL          ", findFirst(a, 5, 99) == NULL, 3);
        check("findFirst(a,5,40) == &a[4]         ", findFirst(a, 5, 40) == &a[4], 2);
    }

    // ---------- TODO #3 : myStrLen ----------
    {
        char s1[] = "Hello";
        char s2[] = "";
        check("myStrLen(\"Hello\") == 5             ", myStrLen(s1) == 5, 7);
        check("myStrLen(\"\") == 0                  ", myStrLen(s2) == 0, 3);
    }

    cout << "---------------------------------------------------" << endl;
    cout << "SCORE: " << gGot << " / " << gMax << endl;
    return 0;
}
