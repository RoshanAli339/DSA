#include <stdio.h>
#include <stdlib.h>

typedef struct CLL
{
    int val;
    struct CLL *next;
}CLL;

int main()
{
    CLL a = {5, NULL};
    printf("%d\n", a.val);
}
