#include <cstddef>
#include "stack.h"

Stack::Stack()
{
    // TODO 1: Set topOfStack to NULL.
    topOfStack = nullptr;
}

Stack::~Stack()
{
    // TODO 2: Pop all nodes until the stack is empty.
    while (topOfStack != nullptr)
    {
        (void)Stack::pop();
    }
}

int Stack::isEmpty()
{
    // TODO 3: Return 1 if the stack is empty, otherwise return 0.
    if (topOfStack == nullptr)
        return 1;
    return 0;
}

void Stack::push(char x)
{
    // TODO 4: Create a new node and put it on top of the stack.
    Node *new_node = new Node;
    new_node->data = x;
    new_node->next = topOfStack;

    topOfStack = new_node;
}

char Stack::pop()
{
    // TODO 5: Remove and return the top value.
    // Return '\0' if the stack is empty.
    if (topOfStack != nullptr)
    {
        Node *tmp = topOfStack;
        char val = topOfStack->data;

        topOfStack = topOfStack->next;
        delete tmp;

        return val;
    }

    return '\0';
}
