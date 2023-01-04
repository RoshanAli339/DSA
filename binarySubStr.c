#include <stdio.h>
#include <string.h>

int main()
{
    int count = 0, max = 0;
    char s[20];
    printf("Enter a string: ");
    scanf(" %[^\n]", s);
    int n = strlen(s);
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '1')
        {
            count++;
        }
        else
        {
            if (count > max)
                max = count;
            count = 0; 
        }
    }
    if (count > max)
    {
        max = count;
    }
    printf("Largest substring is of length: %d\n", max);
}