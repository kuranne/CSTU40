#ifndef STACK_H
#define STACK_H

class Stack {
private:
    struct Node {
        char data;
        Node* next;
    };

    Node* topOfStack;

public:
    Stack();
    ~Stack();
    int isEmpty();
    void push(char x);
    char pop();
};

#endif
