#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int val;
    struct Node *next;
}Node;

Node *top = NULL;

Node* createNode(int v)
{
    Node *n = (Node*)malloc(sizeof(Node));
    n -> val = v;
    n -> next = NULL;
    return n;
}

void push(int v)
{
    Node *newNode = createNode(v);
    newNode -> next = top;
    top = newNode;
}

int pop()
{
    if (!top)
    {
        printf("Stack is empty!\n");
        return -1;
    }
    int v = top -> val;
    Node *t = top;
    top = top -> next;
    free(t);
    return v;
}

int peek()
{
    if (!top)
    {
        printf("Stack is empty!\n");
        return -1;
    }
    return top -> val;
}

void printStack()
{
    if (!top)
    {
        printf("Stack is empty!\n");
        return;
    }
    Node *temp = top;
    while (temp)
    {
        printf("%d ->", temp -> val);
        temp = temp -> next;
    }
    printf("END\n");
}

int main()
{
    push(5);
    push(4);
    push(3);
    push(10);
    push(15);
    printStack();
    pop();
    printStack();
}