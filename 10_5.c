#include <stdio.h>
#include <stdlib.h>

int main()
{
   char n1[100] = "abcde";
    printf("\nGiven string:");
    for(int i =0;i<5;i++)
    {
        printf("%c",n1[i]);
    }

    printf("\nReversed string:");
    for(int i=5-1;i>=1;i--)
    {
        printf("%c",n1[i]);
    }
    return 0;
}