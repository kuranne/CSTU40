#include <iostream>
#include <cstring>
#include <cmath>
#include "student.h"   // include the header only (never include student.cpp)
using namespace std;

// ============================================================
//  This file is COMPLETE. Do NOT modify it.
//  It is a small GRADER: it calls the functions you write in
//  student.cpp and prints PASS / FAIL for each test case.
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

// doubles are compared with a small tolerance, never with ==
static bool almost(double a, double b) {
    return fabs(a - b) < 1e-6;
}

// Fills a record with junk before it is handed to initStudent(),
// so a function that does nothing cannot pass by accident.
static void poison(StudentRecord& s) {
    for (int i = 0; i < NAME_LEN - 1; i++) s.name[i] = '?';
    s.name[NAME_LEN - 1] = '\0';
    for (int i = 0; i < HW_COUNT;   i++) s.hw[i]   = -999;
    for (int i = 0; i < EXAM_COUNT; i++) s.exam[i] = -999;
    s.total = -999;
}

// helper used to build the test data below
static void makeStudent(StudentRecord& s, const char* name, double h, double e) {
    poison(s);
    initStudent(&s, name);
    for (int i = 0; i < HW_COUNT;   i++) s.hw[i]   = h;
    for (int i = 0; i < EXAM_COUNT; i++) s.exam[i] = e;
    updateTotal(&s);
}

int main() {
    cout << "===== Part 3 : struct (40 points) =====" << endl;

    // ---------- TODO #1 : initStudent ----------
    {
        StudentRecord s;
        poison(s);
        initStudent(&s, "Ann");
        check("initStudent: name copied         ", strcmp(s.name, "Ann") == 0, 5);
        check("initStudent: scores cleared      ",
              almost(s.hw[0], 0) && almost(s.hw[HW_COUNT - 1], 0) &&
              almost(s.exam[0], 0) && almost(s.exam[EXAM_COUNT - 1], 0) &&
              almost(s.total, 0), 5);
    }

    // ---------- TODO #2 : updateTotal ----------
    {
        StudentRecord s;
        poison(s);
        initStudent(&s, "Bob");
        s.hw[0] = 1; s.hw[1] = 2; s.hw[2] = 3; s.hw[3] = 4;    // 10
        s.exam[0] = 10; s.exam[1] = 20;                         // 30
        updateTotal(&s);
        check("updateTotal: total == 40         ", almost(s.total, 40), 5);
        updateTotal(&s);   // calling it again must not change anything
        check("updateTotal twice: still 40      ", almost(s.total, 40), 5);
    }

    // ---------- TODO #3 and #4 : array of struct ----------
    {
        StudentRecord list[3];
        makeStudent(list[0], "Ann",  5, 10);   // 4*5  + 2*10 = 40
        makeStudent(list[1], "Bob", 10, 15);   // 4*10 + 2*15 = 70
        makeStudent(list[2], "Cat",  5, 20);   // 4*5  + 2*20 = 60

        check("findTopStudent(list,3) == 1      ", findTopStudent(list, 3) == 1, 6);
        check("findTopStudent(list,0) == -1     ", findTopStudent(list, 0) == -1, 4);

        check("countPassed(list,3,60.0) == 2    ", countPassed(list, 3, 60.0) == 2, 6);
        check("countPassed(list,3,100.0) == 0   ", countPassed(list, 3, 100.0) == 0, 4);
    }

    cout << "---------------------------------------" << endl;
    cout << "SCORE: " << gGot << " / " << gMax << endl;
    return 0;
}
