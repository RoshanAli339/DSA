#include <stdio.h>
#include <stdlib.h>
/*
    Given an array of numbers of size n+1 with all elements between 1 and n(both inclusive)
    Find the number with duplicates
*/


int main()
{
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    int a[20];
    printf("Enter the values of array: ");
    for (int i = 0; i < n+1; ++i)
    {
        scanf("%d", &a[i]);
    }
    int i = 0;
    while (1)
    {
        if (a[abs(a[i])] < 0)
        {
            printf("The number with duplicates is: %d\n", -a[i]);
            break;
        }
        else
        {
            a[abs(a[i])] *= -1;
            i = abs(a[i]);
        }
    }
    
    return 0;
}
