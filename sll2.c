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
        printf("Enter the value: ");
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

SLL *delElement(SLL *head, int ele)
{
    if (!head)
    {
        printf("List is empty!\n");
        return head;
    }
    SLL *p = head, *c;
    if (head -> val == ele)
    {
        head = head -> next;
        free(p);
        return head;
    }
    while (p -> next)
    {
        if (p->next->val == ele)
        {
            c = p -> next;
            p -> next = c -> next;
            free(c);
            return head;
        }
        p = p -> next;
    }
    printf("Element is not found in the list!\n");
    return head;
}

SLL* mergeSortedLists(SLL *h1, SLL *h2)
{
    if (!h1)
        return h2;
    else if (!h2)
        return h1;

    SLL *h3 = NULL, *tail, *node;

    while (h1 || h2)
    {
        if (!h1 && h2)
        {
            node = h2;
            h2 = h2 -> next;
        }
        else if (h1 && !h2)
        {
            node = h1;
            h1 = h1 -> next;
        }
        else if (h1 -> val < h2 -> val)
        {
            node = createNode(h1 -> val);
            h1 = h1 -> next;
        }
        else
        {
            node = createNode(h2 -> val);
            h2 = h2 -> next;
        }

        if (!h3)
        {
            h3 = node;
        }
        else
        {
            tail -> next = node;
        }
        tail = node;
    }
    return h3;
}

SLL* delDuplicatesInSorted(SLL* head)
{
    if (!head)
    {
        printf("List is empty!\n");
        return head;
    }
    SLL *p = head, *c;
    while (p -> next)
    {
        if (p -> val == p->next->val)
        {
            c = p -> next;
            p -> next = c -> next;
            free(c);
        }
        else
            p = p -> next;
    }
    return head;
}

SLL* delDuplicates(SLL *head)
{
    if (!head)
    {
        printf("List is empty!\n");
        return head;
    }

    SLL *p = head, *c, *t;

    while (p -> next)
    {
        c = p;
        while (c -> next)
        {
            if (p -> val == c -> next -> val)
            {
                t = c -> next;
                c -> next = t -> next;
                free(t);
            }
            else
                c = c -> next;
        }
        p = p -> next;
    }
    return head;
}

SLL* delFromEnd(SLL *head, int pos)
{
    int l = listSize(head);
    return delPosition(head, l - pos + 1);
}

int findMiddle(SLL *head)
{
    int l = listSize(head) / 2;
    for (int i = 1; i <= l; ++i)
    {
        head = head -> next;
    }
    return head -> val;
}

SLL* selectionSort(SLL *head)
{
    SLL *p = head, *c, *least;
    while (p -> next)
    {
        least = p;
        c = p -> next;
        while (c)
        {
            if (c -> val < least -> val)
                least = c;
            c = c -> next;
        }
        int temp = least -> val;
        least -> val = p -> val;
        p -> val = temp;
        p = p -> next;
    }
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

    printf("Enter position to delete: ");
    scanf("%d", &n);
    head = delPosition(head, n);
    printList(head);

    printf("Enter element to delete: ");
    scanf("%d", &v);
    head = delElement(head, v);
    printList(head);
    
    printf("Enter number of elements of second list: ");
    scanf("%d", &v);
    SLL *head2 = createList(v);
    printList(head2);

    printf("After merging the two lists: ");
    SLL *head3 = mergeSortedLists(head, head2);
    printList(head3);
    */

    printf("After deleting the duplicates: ");
    head = delDuplicates(head);
    printList(head);

    /*    
    printf("Enter a position from end to delete: ");
    scanf("%d", &n);
    head = delFromEnd(head, n);
    printList(head);

    v = findMiddle(head);
    printf("The middle element of the list: %d\n", v);
    
    printf("After sorting the list is: ");
    head = selectionSort(head);
    printList(head);
    */
    return 0;
}