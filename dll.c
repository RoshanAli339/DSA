#include <stdio.h>
#include <stdlib.h>

typedef struct DLL
{
    int val;
    struct DLL *prev, *next;
}DLL;

DLL* createNode(int v)
{
    DLL *node = (DLL*)malloc(sizeof(DLL));
    node -> val = v;
    node -> prev = NULL;
    node -> next = NULL;
    return node;
}

DLL* createList(int n)
{
    int v;
    DLL *head = NULL, *tail, *node;
    printf("Enter the elements of the list: ");
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &v);
        node = createNode(v);
        if (!head)
            head = node;
        else
        {
            node -> prev = tail; 
            tail -> next = node;
        }
        tail = node;
    }
    return head;
}

void printList(DLL *head)
{
    while (head)
    {
        printf("%d <=> ", head -> val);
        head = head -> next;
    }
    printf("END\n");
}

int main(int argc, char const *argv[])
{
    int n;
    printf("Enter the no.of terms: ");
    scanf("%d", &n);
    DLL *head = createList(n);
    printList(head);
    return 0;
}
