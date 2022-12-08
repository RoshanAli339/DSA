#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct emp
{
    char name[50], org[50];
    int num;
    struct emp *next;
}emp;

emp* createEmp(char *nm, int n, char *o)
{
    emp *e = (emp*)malloc(sizeof(emp));
    strcpy(e -> name, nm);
    strcpy(e -> org, o);
    e -> num = n;
    return e;
}

void displayEmp(emp *e)
{
    printf("\tName: %s\n", e -> name);
    printf("\tSerial no.: %d\n", e -> num);
    printf("\tOrganization: %s\n", e -> org);
}

emp** createArray(int n)
{
    emp **e = (emp**)malloc(n * sizeof(emp*));
    for (int i = 0; i < n; ++i)
    {
        e[i] = NULL;
    }
    return e;
}

emp* insertAtStart(emp *head, emp *node)
{
    node -> next = head;
    return node;
}

void inputData(emp **e)
{
    char empName[50], empOrg[50];
    int n;
    while (1)
    {
        printf("Enter serial no. of employee or 0 to exit: ");
        scanf("%d", &n);
        if (n == 0) break;
        printf("Enter employee name: ");
        scanf(" %[^\n]", empName);
        printf("Enter organization name: ");
        scanf(" %[^\n]", empOrg);
        emp *employee = createEmp(empName, n, empOrg);
        int index = n % 10;
        if (*(e + index) == NULL)
        {
            *(e + index) = employee;
        }
        else
        {
            *(e + index) = insertAtStart(*(e+index), employee);
        }
    }
}

void searchEmp(emp **head, int empNum)
{
    int index = empNum % 10;
    if (!head || !head[index])
    {
        printf("Employee not found!\n");
        return;
    }
    if (empNum == head[index] -> num)
    {
        displayEmp(head[index]);
        return;
    }
    else if (head[index] -> next != NULL)
    {
        emp *t = head[index] -> next;
        while (t)
        {
            if (t -> num == empNum)
            {
                displayEmp(t);
                return;
            }
            t = t -> next;
        }
    }
    printf("Employee details not found!\n");
    return;
}

void delEmp(emp **head, int n)
{
    int index = n % 10;
    if (!head || !head[index])
    {
        printf("Employee details not found!\n");
        return;
    }
    if (head[index] -> num == n)
    {
        emp *t = head[index];
        if (t -> next != NULL)
            head[index] = t -> next;
        else
            head[index] = NULL;
        free(t);
        printf("Record deleted!\n");
        return;
    }
    else if (head[index] -> next != NULL)
    {
        emp *t = head[index];
        while (t -> next)
        {
            if (t -> next -> num == n)
            {
                emp *c = t -> next;
                t -> next = NULL;
                free(c);
                printf("Record deleted!\n");
                return;
            }
            t = t -> next;
        }
    }
    printf("Employee not found!\n");
    return;
}

void displayHash(emp **head, int n)
{
    for (int i = 0; i < n; ++i)
    {
        emp *t = head[i];
        while (t)
        {
            displayEmp(t);
            t = t -> next;
        }
        printf("END%d\n", i);
    }
}

int main()
{
    emp **head = createArray(10);
    inputData(head);
    int num;
    displayHash(head, 10);
    printf("Enter employee serial no.: ");
    scanf("%d", &num);
    searchEmp(head, num);
    printf("Enter employee serial no.: ");
    scanf("%d", &num);
    delEmp(head, num);
    displayHash(head, 10);
}