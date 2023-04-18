#include <stdio.h>
#include <stdlib.h>

int main()
{
    char Up_Lp[101]="abcde";
    printf("Given lowercase letters:%s",Up_Lp);
    printf("\nConverted uppercase letters are:");
    for(int i=0;i<5;i++)
    {
        printf("%c",Up_Lp[i]-32);
    }

    return 0;
}