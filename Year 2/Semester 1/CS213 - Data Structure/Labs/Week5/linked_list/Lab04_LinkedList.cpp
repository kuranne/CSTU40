/*
============================================================
CS213 Data Structures
Lab 02: Linked List Problem Solving
============================================================

ชื่อ-นามสกุล:  วิรากร ธนบัตร
รหัสนักศึกษา:  6809617415

คำชี้แจง
- แก้ไขเฉพาะบริเวณ STUDENT CODE และ TODO
- ห้ามเปลี่ยนชื่อฟังก์ชันหรือ parameters
- ห้ามแก้ไข Lab02_LinkedList_v2.h และ main_lab02_v2.cpp
- ส่งเฉพาะไฟล์ Lab02_LinkedList_v2.cpp
============================================================
*/

#include <iostream>
#include "Lab04_LinkedList.h"
using namespace std;

// ============================================================
// ส่วนที่ A: Pointer Trace [1.5 คะแนน]
// ============================================================
/*
พิจารณาลิสต์ต่อไปนี้

head
 |
 v
10 -> 20 -> 30 -> 40 -> nullptr

ให้ p เริ่มต้นที่ head และทำคำสั่งต่อไปนี้

Node* p = head;
p = p->next;
p->next = p->next->next;

A1. หลังจาก p = p->next; ตัวแปร p ชี้ไปยัง node ที่มีค่าเท่าใด
TODO: 20

A2. หลังจาก p->next = p->next->next; ลิสต์ที่เข้าถึงได้จาก head
    มีค่าอะไรบ้างตามลำดับ
TODO: 20, 40, nullptr

A3. node ค่า 30 ถูก delete หรือไม่ เพราะเหตุใด
TODO: ไม่ถูก delete เพราะไม่มี method delete รันในคำสั่ง แต่ก็ไม่สามารถเข้าถึงได้อีก
*/

// ============================================================
// โค้ดพื้นฐานของ Node และ List
// ============================================================
Node::Node(int value)
{
    info = value;
    next = nullptr;
}

List::List()
{
    head = nullptr;
}

List::~List()
{
    Node *p = head;
    while (p != nullptr)
    {
        Node *nextNode = p->next;
        delete p;
        p = nextNode;
    }
}

bool List::emptyList() const
{
    return head == nullptr;
}

void List::insertLast(int value)
{
    Node *newNode = new Node(value);

    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    Node *p = head;
    while (p->next != nullptr)
        p = p->next;

    p->next = newNode;
}

void List::printList() const
{
    Node *p = head;

    if (p == nullptr)
    {
        cout << "(empty)" << endl;
        return;
    }

    while (p != nullptr)
    {
        cout << p->info;
        if (p->next != nullptr)
            cout << " -> ";
        p = p->next;
    }
    cout << endl;
}

// ============================================================
// ส่วนที่ B: insertBefore(target, value) [2.5 คะแนน]
// ============================================================
/*
เพิ่ม node ใหม่ที่มีค่า value ไว้ "ก่อน" node แรกที่มีค่า target

ตัวอย่าง:
10 -> 20 -> 30 -> 40
insertBefore(30, 25)
10 -> 20 -> 25 -> 30 -> 40

เงื่อนไข
- ถ้า target อยู่ที่ head ต้องแทรกก่อน head ได้ถูกต้อง
- ถ้าไม่พบ target ไม่ต้องเปลี่ยนลิสต์
- ถ้าลิสต์ว่าง ไม่ต้องทำอะไร
*/
void List::insertBefore(int target, int value)
{
    // ===== STUDENT CODE =====
    // TODO:
    // next = target => curr -> new, new -> next
    Node *newNode = new Node(value);
    Node *curr = head;
    if (curr->info == target)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    while (curr->next != nullptr)
    {
        if (curr->next->info == target)
        {
            Node *tmp = curr->next;
            curr->next = newNode;
            newNode->next = tmp;
            return;
        }
        curr = curr->next;
    }
    // ===== END STUDENT CODE =====
}

// ============================================================
// ส่วนที่ C: moveToFront(value) [2.5 คะแนน]
// ============================================================
/*
ย้าย node แรกที่มีค่า value มาไว้หน้าสุดของลิสต์
โดยต้องใช้ node เดิม

ตัวอย่าง:
10 -> 20 -> 30 -> 40
moveToFront(30)
30 -> 10 -> 20 -> 40

เงื่อนไขสำคัญ
- ห้ามใช้ new
- ห้ามใช้ delete
- ห้ามเปลี่ยนค่า info ของ node เพื่อเลียนแบบการย้าย
- ถ้า value อยู่ที่ head แล้ว ไม่ต้องเปลี่ยนอะไร
- ถ้าไม่พบ value ไม่ต้องเปลี่ยนลิสต์
*/
void List::moveToFront(int value)
{
    // ===== STUDENT CODE =====
    // TODO:
    if (head->info == value)
        return;

    Node *prev = head;
    Node *curr = prev->next;

    while (curr != nullptr)
    {
        if (curr->info == value)
        {
            prev->next = curr->next;
            curr->next = head;
            head = curr;
            return;
        }
        prev = curr;
        curr = curr->next;
    }

    // ===== END STUDENT CODE =====
}

// ============================================================
// ส่วนที่ D: removeAfter(value) [2.0 คะแนน]
// ============================================================
/*
ลบ node ที่อยู่ "ถัดจาก" node แรกที่มีค่า value

ตัวอย่าง:
10 -> 20 -> 30 -> 40
removeAfter(20)
10 -> 20 -> 40

เงื่อนไข
- ต้องคืนหน่วยความจำของ node ที่ถูกลบด้วย delete
- ถ้า value เป็น node สุดท้าย ไม่ต้องทำอะไร
- ถ้าไม่พบ value ไม่ต้องทำอะไร
- ถ้าลิสต์ว่าง ไม่ต้องทำอะไร
*/
void List::removeAfter(int value)
{
    // ===== STUDENT CODE =====
    // TODO:
    Node *curr = head;
    Node *next = curr->next;

    while (next != nullptr)
    {
        if (curr->info == value)
        {
            Node *tmp = next;
            curr->next = next->next;
            next->next = nullptr;
            delete tmp;
            return;
        }
        curr = next;
        next = next->next;
    }
    // ===== END STUDENT CODE =====
}

// ============================================================
// ส่วนที่ E: Concept Check [1.5 คะแนน]
// ============================================================
/*
E1. ใน moveToFront() เพราะเหตุใดจึงไม่ควรสร้าง node ใหม่
    แล้ว copy ค่าเดิมมาไว้ข้างหน้า
TODO: เพราะการสร้าง Node ใหม่ ทั้งกินพื้นที่เพิ่มขึ้นและต้อง delete Node เก่าด้วย Operator มันเยอะและเสี่ยงให้โปรแกรมช้าลง

E2. ใน removeAfter() เพราะเหตุใดควรเก็บ pointer ของ node
    ที่จะลบไว้ก่อน แล้วจึงเปลี่ยน link
TODO: เพราะหากเปลี่ยน link ก่อนโดยไม่ได้เก็บ pointer ที่ชี้ไปยังตัวที่จะลบ จะไม่สามารถใช้ delete เพื่อลบตัวที่จะลบได้

E3. ถ้าเราปรับ pointer ข้าม node หนึ่งไป แต่ไม่ delete node นั้น
    จะเกิดปัญหาอะไร
TODO: Memory Leak
*/
