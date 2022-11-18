#include <stdio.h>
#include <stdlib.h>

typedef struct SLL
{
    int data;
    struct SLL *next;
}
SLL;

SLL* createNode(int v)
{
    SLL *node = (SLL*)malloc(sizeof(SLL));
    node -> data = v;
    node -> next = NULL;
}

SLL* createList(int n)
{
    int v;
    SLL *head = NULL, *tail, *newNode;
    printf("Enter the elements of the list: \n");

    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &v);
        newNode = createNode(v);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            tail -> next = newNode;
        }
        tail = newNode;
    }
    return head;
}

void printList(SLL *head)
{
    while (head)
    {
        printf("%d -> ", head -> data);
        head = head -> next;
    }
    printf("END\n");
}

int main(int argc, char const *argv[])
{
    int n;
    printf("Enter the no. of elements of the list: ");
    scanf("%d", &n);

    SLL *head = createList(n);

    printList(head);
    return 0;
}
