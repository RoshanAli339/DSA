#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    int a[50];
    printf("Enter the values of array: ");
    for (int i = 0; i < n + 1; ++i)
    {
        scanf("%d", &a[i]);
    }
    int i = 0;
    while (1)
    {
        if (a[abs(a[i])] < 0 )
        {
            printf("Repeated number is: %d\n", -a[i]);
            break;
        }
        else
        {
            a[abs(a[i])] *= -1;
            i = abs(a[i]);
        }
    }
    
}