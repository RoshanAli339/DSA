#include <stdio.h>

int q[5], f = -1, r = -1;

void insertAtStart(int v)
{
        if (r == 4)
        {
                printf("Queue overflow!\n");
                return;
        }
        if (f == -1)
        {
                q[++f] = v;
                ++r;
                return;
        }
        for (int j = r; j >= f; --j)
                q[j+1] = q[j];
        r++;
        q[f] = v;
}

void insertAtEnd(int v)
{
        if (r == 4)
        {
                printf("Queue overflow!\n");
                return;
        }
        q[++r] = v;
        if (f == -1) f++;
}

int delFromStart()
{
        if (f == -1)
        {
                printf("Queue underflow!\n");
                return -99;
        }
        return q[f++];
}

int delFromEnd()
{
        if (f == -1)
        {
                printf("Queue underflow!\n");
                return -99;
        }
        q[r--];
}

void printQueue()
{
        for (int i = f; i <= r; i++)
        {
                printf("%d ", q[i]);
        }
        printf("\n");
}

int main()
{
        insertAtStart(3);
        insertAtStart(5);
        insertAtEnd(12);
        insertAtEnd(15);
        printQueue();
        delFromStart();
        delFromEnd();
        printQueue();
}