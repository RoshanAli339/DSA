#include <stdio.h>
#include <string.h>

int main()
{
    int count = 0, max = 0;
    char s[20];
    printf("Enter a string: ");
    scanf(" %s", s);
    int n = strlen(s);
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
            count++;
        else
        {
            if (count > max)
                max = count;
            count = 0;
        }
    }
    if (count > max)
        max = count;
    printf("Length of longest substring with 1's: %d\n", max); 
    
    return 0;
}
