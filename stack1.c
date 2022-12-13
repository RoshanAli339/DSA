#include <stdio.h>

int stk[10], top = -1;

void push(int v)
{
    if (top == 9)
    {
        printf("Stack is full!!\n");
        return;
    }
    top += 1;
    stk[top] = v;
}

int pop()
{
    if (top == -1)
    {
        printf("Stack is empty!\n");
        return -1;
    }
    return stk[top--];
}

int peek()
{
    if (top == -1)
    {
        printf("Stack is empty!\n");
        return -1;
    }
    return stk[top];
}

void printStack()
{
    if (top == -1)
    {
        printf("Stack is empty!\n");
        return;
    }
    for (int temp = top; temp >= 0; --temp)
    {
        printf("%d -> ", stk[temp]);
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