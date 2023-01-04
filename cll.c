#include <stdio.h>
#include <stdlib.h>

typedef struct CLL
{
    int val;
    int count;
    struct CLL *next;
}CLL;

CLL* createNode(int v)
{
    CLL *node = (CLL*)malloc(sizeof(CLL));
    node -> val = v;
    node -> count = 0;
    node -> next = NULL;
    return node;
}

CLL* createList(int n)
{
    int v;
    printf("Enter the elements of list: \n");
    CLL *tail = NULL, *newNode;
    for (int i = 0; i < n; ++i)
    {
        printf("Enter the value: ");
        scanf("%d", &v);
        newNode = createNode(v);
        if (!tail)
        {
            newNode -> next = newNode;
            tail = newNode;
        }
        else
        {
            newNode -> next = tail -> next;
            tail -> next = newNode;
            tail = newNode;
        }
    }
    return tail;
}

void detectCycle(CLL *tail)
{
    if (!tail)
    {
        printf("List is empty!\n");
        return;
    }
    CLL *t = tail;
    while (t -> next)
    {
        if (t -> count > 0)
        {
            printf("Cycle is found at value: %d\n", t -> val);
            return;
        }
        t -> count += 1;
        t = t -> next;
    }
}

int main()
{
    int n;
    printf("Enter size of list: ");
    scanf("%d", &n);
    CLL *tail = createList(n);
    detectCycle(tail);
}