/*
============================================================
CS213 Data Structures
Lab 02 - Test Program
============================================================

DO NOT MODIFY THIS FILE
============================================================
*/

#include <iostream>
#include "Lab04_LinkedList.h"
using namespace std;

void printTitle(const string& title)
{
    cout << "\n=== " << title << " ===" << endl;
}

int main()
{
    List list;

    printTitle("Initial List");
    list.insertLast(10);
    list.insertLast(20);
    list.insertLast(30);
    list.insertLast(40);
    list.printList();

    printTitle("Part B: insertBefore");
    list.insertBefore(30, 25);
    list.printList();                  // 10 -> 20 -> 25 -> 30 -> 40

    list.insertBefore(10, 5);
    list.printList();                  // 5 -> 10 -> 20 -> 25 -> 30 -> 40

    list.insertBefore(99, 88);
    list.printList();                  // unchanged

    printTitle("Part C: moveToFront");
    list.moveToFront(25);
    list.printList();                  // 25 -> 5 -> 10 -> 20 -> 30 -> 40

    list.moveToFront(25);
    list.printList();                  // unchanged

    list.moveToFront(99);
    list.printList();                  // unchanged

    printTitle("Part D: removeAfter");
    list.removeAfter(20);
    list.printList();                  // 25 -> 5 -> 10 -> 20 -> 40

    list.removeAfter(40);
    list.printList();                  // unchanged

    list.removeAfter(99);
    list.printList();                  // unchanged

    return 0;
}
