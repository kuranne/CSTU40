#include "SLinkedList.h"

SLinkedList::SLinkedList()
{
    head = nullptr;
    tail = nullptr;
}

SLinkedList::~SLinkedList()
{
    while (head != nullptr)
    {
        SLinkedList::removeFromHead();
    }
}

void SLinkedList::addToTail(Account *acc)
{
    SLinkedList::Node *new_acc_node = new SLinkedList::Node(acc);
    tail->next = new_acc_node;
    tail = tail->next;
    if (head == nullptr)
    {
        head = tail;
    }
}

void SLinkedList::removeFromHead()
{
    if (head == nullptr)
        return;
    SLinkedList::Node *tmp = head;
    head = head->next;
    delete tmp;
}

int SLinkedList::countList()
{
    int count = 0;
    SLinkedList::Node *curr = head;

    while (curr != nullptr)
    {
        ++count;
        curr = curr->next;
    }

    return count;
}