#include <stdio.h>
#include <stdlib.h>

typedef struct Term
{
    int coeff, exp;
    struct Term *next;
}Term;

Term* createTerm(int c, int e)
{
    Term *term = (Term*)malloc(sizeof(Term));
    term -> coeff = c;
    term -> exp = e;
    term -> next = NULL;
    return term;
}

Term* createPoly(int n)
{
    printf("Enter the coefficients and exponents: \n");
    int c, e;
    Term *head = NULL, *tail, *term;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d %d", &c, &e);
        term = createTerm(c, e);
        if (!head)
            head = term;
        else 
            tail -> next = term;
        tail = term;
    }
    return head;
}

void printPoly(Term *head)
{
    while (head -> next)
    {
        printf("%dx^%d + ", head -> coeff, head -> exp);
        head = head -> next;
    }
    if (head -> exp == 0)
        printf("%d\n", head -> coeff);
    else
        printf("%dx^%d\n", head -> coeff, head -> exp);
}

Term *addPoly(Term *p1, Term *p2)
{
    if (!p1)
        return p2;
    else if (!p2)
        return p1;

    Term *head = NULL, *tail, *term;
    while (p1 || p2)
    {
        if (p1 && !p2)
        {
            term = createTerm(p1 -> coeff, p1 -> exp);
            p1 = p1 -> next;
        }
        else if (!p1 && p2)
        {
            term = createTerm(p2 -> coeff, p2 -> exp);
            p2 = p2 -> next;
        }
        else if (p1 -> exp == p2 -> exp)
        {
            term = createTerm(p1 -> coeff + p2 -> coeff, p1 -> exp);
            p1 = p1 -> next;
            p2 = p2 -> next;
        }
        else if (p1 -> exp > p2 -> exp)
        {
            term  = createTerm(p1 -> coeff, p1 -> exp);
            p1 = p1 -> next;
        }
        else
        {
            term = createTerm(p2 -> coeff, p2 -> exp);
            p2 = p2 -> next;
        }
        
        if (!head)
            head = term;
        else
            tail -> next = term;
        tail = term;
    }
    return head;
}

void swap(Term *x, Term *y)
{
    int tc = x -> coeff;
    int te = x -> exp;
    x -> coeff = y -> coeff;
    x -> exp = y -> exp;
    y -> coeff = tc;
    y -> exp = te;
}

Term* selectionSort(Term *head)
{
    if (!head)
    {
        printf("Polynomial does not exist!\n");
        return head;
    }

    Term *p = head, *c, *big;
    while (p -> next)
    {
        big = p;
        c = p -> next;
        while (c)
        {
            if (c -> exp > big -> exp)
                big = c;
            c = c -> next;
        }
        swap(p, big);
        p = p -> next;
    }
    return head;
}

Term* simplifyPoly(Term *head)
{
    if (!head)
    {
        printf("Polynomial does not exist!\n");
        return head;
    }

    Term *p = head, *c;

    while (p -> next)
    {
        if (p -> exp == p -> next -> exp)
        {
            c = p -> next;
            p -> coeff = p -> coeff + c -> coeff;
            p -> next = c -> next;
            free(c);
        }
        p = p -> next;
    }
    return head;
}

Term* multiplyPoly(Term *p1, Term *p2)
{
    if (!p1)
        return p2;
    else if (!p2)
        return p1;
    
    Term *head = NULL, *tail, *term, *t;

    while (p1)
    {
        t = p2;
        while (t)
        {
            term = createTerm(p1 -> coeff * t -> coeff, p1 -> exp + t -> exp);
            if (!head)
                head = term;
            else 
                tail -> next = term;
            tail = term;
            t = t -> next;
        }
        p1 = p1 -> next;
    }
    head = selectionSort(head);
    head = simplifyPoly(head);
    return head;
}

int main(int argc, char const *argv[])
{
    int n1, n2;
    printf("Enter no.of terms of first polynomial: ");
    scanf("%d", &n1);
    Term *head1 = createPoly(n1);
    printf("Enter no.of terms of second polynomial: ");
    scanf("%d", &n2);
    Term *head2 = createPoly(n2);
    head1 = selectionSort(head1);
    head2 = selectionSort(head2);

    Term *head3 = addPoly(head1, head2);
    printPoly(head1);
    printf("+\n");
    printPoly(head2);
    printf("=\n");
    printPoly(head3);

    head3 = multiplyPoly(head1, head2);
    printPoly(head1);
    printf("*\n");
    printPoly(head2);
    printf("=\n");
    printPoly(head3);
    return 0;
}
