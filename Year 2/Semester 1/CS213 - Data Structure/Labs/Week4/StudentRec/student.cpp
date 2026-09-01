#include <cstring>     // strcpy, strncpy
#include "student.h"

// ============================================================
//  TODO #1  -- implement initStudent()
//
//  's' is a POINTER to a StudentRecord, so reach its members
//  with the arrow operator:   s->name , s->hw[i] , s->total
//  (that is the same as  (*s).name ).
//
//  Do:
//    (a) copy the C string 'name' into the char array s->name
//        -> strcpy(s->name, name);
//    (b) set every s->hw[i] and every s->exam[i] to 0
//        (use HW_COUNT and EXAM_COUNT, never a magic number)
//    (c) set s->total to 0
// ============================================================
void initStudent(StudentRecord* s, const char* name) {

    // >>> write your code here <<<
    strcpy(s->name, name);
    for (int i = 0; i < HW_COUNT; i++) *(s->hw + i) = 0;
    for (int i = 0; i < EXAM_COUNT; i++) *(s->exam + i) = 0;
    s->total = 0;
}

// ============================================================
//  TODO #2  -- implement updateTotal()
//
//  Set s->total to the sum of all HW_COUNT homework scores plus
//  all EXAM_COUNT exam scores.
//
//  CAREFUL: start by setting s->total = 0, otherwise calling
//  updateTotal() twice would add everything twice.
// ============================================================
void updateTotal(StudentRecord* s) {

    // >>> write your code here <<<
    s->total = 0;
    for (int i = 0; i < HW_COUNT; i++) s->total += *(s->hw + i);
    for (int i = 0; i < EXAM_COUNT; i++) s->total += *(s->exam + i);
}

// ============================================================
//  TODO #3  -- implement findTopStudent()
//
//  'list' is an ARRAY OF struct. Element i is list[i] and its
//  total is  list[i].total  (dot, not arrow -- list[i] is an
//  object, not a pointer).
//
//  Return the index of the largest total.
//  On a tie keep the SMALLER index (so only replace the best
//  when you find something strictly greater).
//  Return -1 if n <= 0.
// ============================================================
int findTopStudent(const StudentRecord list[], int n) {
    if (n <= 0) return -1;

    // >>> write your code here <<<
    int max = list[0].total;
    int imax = 0;
    for (int i = 1; i < n; i++) {
        if (list[i].total > max) {
            imax = i;
            max = list[i].total;
        }

        if (i == n - 1) return imax;
    }

    return 0;
}

// ============================================================
//  TODO #4  -- implement countPassed()
//
//  Count how many records in list[0..n-1] have
//      total >= minTotal
//  and return that count.
// ============================================================
int countPassed(const StudentRecord list[], int n, double minTotal) {
    int count = 0;

    // >>> write your code here <<<
    for (int i = 0; i < n; i++) if (list[i].total >= minTotal) count++;

    return count;
}
