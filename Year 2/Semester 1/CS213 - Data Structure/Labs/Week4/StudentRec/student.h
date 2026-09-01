#ifndef STUDENT_H
#define STUDENT_H

// ============================================================
//  Lab 3 - Part 3 : struct
//  Struct definition + declarations.
//  (This file is COMPLETE. Do NOT modify.)
// ============================================================

const int NAME_LEN   = 32;   // room for the name, including '\0'
const int HW_COUNT   = 4;    // number of homework scores
const int EXAM_COUNT = 2;    // number of exam scores

// A container that keeps everything about one student together.
struct StudentRecord {
    char   name[NAME_LEN];      // student name (a C string)
    double hw[HW_COUNT];        // homework scores
    double exam[EXAM_COUNT];    // exam scores
    double total;               // total score
};

// Sets up the record pointed to by s:
//   - copies 'name' into s->name
//   - sets every hw[], every exam[] and total to 0
void initStudent(StudentRecord* s, const char* name);

// Recomputes s->total = (sum of all hw) + (sum of all exam).
// Calling it twice in a row must NOT double the total.
void updateTotal(StudentRecord* s);

// Returns the INDEX of the student with the highest 'total'
// in an array of n records.  On a tie, the smaller index wins.
// Returns -1 when n <= 0.
int findTopStudent(const StudentRecord list[], int n);

// Returns how many of the n records have total >= minTotal.
int countPassed(const StudentRecord list[], int n, double minTotal);

#endif // STUDENT_H
