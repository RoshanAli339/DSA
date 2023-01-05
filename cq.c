#include <stdio.h>

int q[5], f = -1, r = -1;

void enqueue(int v)
{
        if ((r+1)%5==f)
        {
                printf("Queue overflow\n");
                return;
        }
        r = (r+1)%5;
        q[r] = v;
        if (f == -1) f++;
}

int dequeue()
{
        if (f == -1)
        {
                printf("Queue underflow\n");
                return -99;
        }
        int v = q[f];
        if (f == r)
        {
                f = -1;
                r = -1;
                return v;
        }
        f = (f+1)%5;
        return v;
}

void printQueue()
{
        for (int i = f; i != r; i=(i+1)%5)
        {
                printf("%d ",q[i]);
        }
        printf("%d\n", q[r]);
}

int main()
{
        enqueue(12);
        enqueue(16);
        enqueue(21);
        enqueue(25);
        enqueue(28);
        printQueue();
        for (int i = 0; i < 4; ++i)
                dequeue();
        enqueue(27);
        printQueue();
}
