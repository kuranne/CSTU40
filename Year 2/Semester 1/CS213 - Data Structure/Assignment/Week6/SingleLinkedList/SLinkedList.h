#ifndef SLINKEDLIST_H_INCLUDED
#define SLINKEDLIST_H_INCLUDED

#include "Account.h"

class SLinkedList{
public:
    struct Node{
        Node* next;
        Account* account;
        Node(Account* acc){
            account = acc;
            next = NULL;
        }
    };

    Node *head;
    Node *tail;

    SLinkedList();
    ~SLinkedList();
    void addToTail(Account*);
    void removeFromHead();
    int countList();
};

#endif // SLINKEDLIST_H_INCLUDED
