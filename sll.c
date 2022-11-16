#include <stdio.h>
#include <stdlib.h>

typedef struct sll
{
    int val;
    struct sll *next;
}sll;

sll* createNode(int v)
{
    sll *node = (sll*)malloc(sizeof(sll));
    node -> val = v;
    node ->next = NULL;
    return node;
}

sll* createList(int n)
{
    int v;
    sll *head = NULL, *tail = NULL, *newN;
    printf("Enter the elements of list:\n");
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &v);
        newN = createNode(v);
        if (head == NULL)
        {
            head = newN;
        }
        else
        {
            tail -> next = newN;
        }
        tail = newN;
    }
    return head;
}

sll* addAtHead(sll *head, int v)
{
    sll *node = (sll*)malloc(sizeof(sll));
    node -> val = v;
    node -> next = head;
    return node;
}

void addAtTail(sll *head, int v)
{
    while (head->next != NULL)
    {
        head = head->next;
    }
    sll *node = (sll*)malloc(sizeof(sll));
    node -> val = v;
    node -> next = NULL;
    head->next = node;
}

void insertNode(sll *head, int n, int v)
{   
    int s = 1;
    while (head)
    {
        if (s == n - 1)
        {
            sll *node = (sll*)malloc(sizeof(sll));
            node -> val = v;
            node -> next = head->next;
            head -> next = node;
            break;
        }
        else{
            head = head->next;
            s++;
        }
    }
}

void printList(sll *head)
{
    while (head)
    {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("END\n");
}

int main(int argc, char const *argv[])
{

    //creating and printing a linked list
    printf("Enter number of list elements: ");
    int n;
    scanf("%d", &n);
    sll *head = createList(n);
    printList(head);

    //adding a node at the head
    printf("Enter the value to add at the head: ");
    int v;
    scanf("%d", &v);
    head = addAtHead(head, v);
    printList(head);

    //adding a node at the tail
    printf("Enter the value to add at the tail: ");
    scanf("%d", &v);
    addAtTail(head, v);
    printList(head);

    //inserting a node in between the list at a given position
    printf("Enter position and value to insert in the list: ");
    scanf("%d %d", &n, &v);
    insertNode(head, n, v);
    printList(head);
}
