#include <stdio.h>
#include <stdlib.h>

typedef struct SLL
{
    int val;
    struct SLL *next;
}
SLL;

SLL* createNode(int v)
{
    SLL *node = (SLL*)malloc(sizeof(SLL));
    node->val = v;
    node->next = NULL;
    return node;
}

SLL* createList(int n)
{
    SLL *head = NULL, *tail, *newN;
    int v;
    printf("Enter the elements of the list: \n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v);
        newN = createNode(v);
        if (head == NULL)
            head = newN;
        else
            tail -> next = newN;
        tail = newN;
    }
    return head;
}

SLL* insertAtStart(SLL *head, SLL *node)
{
    node->next = head;
    head = node;
    return head;
}

SLL* insertAtEnd(SLL *head, SLL *node)
{
    SLL *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = node;
    return head;
}

int listSize(SLL *head)
{
    int s = 0;
    while (head != NULL)
    {
        s++;
        head = head->next;
    }
    return s;
}

SLL* insertNode(SLL *head, SLL *node, int pos)
{
    int l = listSize(head);
    if (pos <= 1) 
        return insertAtStart(head, node);
    else if (pos >= (l+1))
        return insertAtEnd(head, node);

    SLL *t = head;
    for (int i = 1; i < pos - 1; ++i)
    {
        t = t->next;
    }
    node -> next = t -> next;
    t -> next = node;
    return head;
}

SLL* insertInSortedList(SLL *head, SLL *node)
{
    SLL *t = head;
    int p = 0;
    if (!t)
        return node;
    while (t != NULL && t->val < node -> val)
    {
        p++;
        t = t->next;
    }
    head = insertNode(head, node, p+1);
    return head;
}

SLL* delPosition(SLL *head, int pos)
{
    int l = listSize(head);
    if (pos < 1 || pos > l)
    {
        printf("Invalid position or list is empty!\n");
        return head;
    }
    
    SLL *c, *p = head;
    if (pos == 1)
    {
        head = head -> next;
        free(p);
        return head;
    }
    for (int i = 1; i < pos - 1; ++i)
    {
        p = p -> next;
    }
    c = p->next;
    p->next = c->next;
    free(c);
    return head;
}


void printList(SLL *head)
{
    while (head)
    {
        printf("%d -> ", head->val);
        head = head -> next;
    }
    printf("END\n");
}

int main()
{
    int n, v;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    SLL *head = createList(n), *node;
    printList(head);    

    /*
    printf("Enter the value to add at the start: ");
    scanf("%d", &v);
    node = createNode(v);
    head = insertAtStart(head, node);
    printList(head);

    printf("Enter the value to add at the end: ");
    scanf("%d", &v);
    node = createNode(v);
    head = insertAtEnd(head, node);
    printList(head);    


    printf("Enter the element and position to insert a new element: ");
    scanf("%d %d", &v, &n);
    node = createNode(v);
    head = insertNode(head, node, n);
    printList(head);

    printf("Enter the element to insert in the sorted list: ");
    scanf("%d", &v);
    node = createNode(v);
    head = insertInSortedList(head, node);
    printList(head);
    */

    printf("Enter position to delete: ");
    scanf("%d", &n);
    head = delPosition(head, n);
    printList(head);
    return 0;
}