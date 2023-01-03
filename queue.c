#include <stdio.h>
#include <stdlib.h>

int queue[10], f = -1, r = -1;

void enqueue(int c)
{
    if (r == 9)
    {
        printf("Queue is full!\n");
        return;
    }
    queue[++r] = c;
    if (f == -1)    f++;
}

int dequeue()
{
    if (f == -1 || f > r)
    {
        printf("Queue is empty!\n");
        return -99;
    }
    return queue[f++];
}

void printQueue()
{
    for (int i = f; i <= r; ++i)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main()
{
    enqueue(5);
    enqueue(12);
    enqueue(14);
    enqueue(15);
    printQueue();
    dequeue();
    printQueue();
}