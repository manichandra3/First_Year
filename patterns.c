#include<stdio.h>
int main()
{
    int i, n, j;
    for (i=1;i<=5;i++) //Rows.
    {
        for (n=i; n<5; n++) //Columns.
        {
            printf(" ");
        }
        for (j=1;j<=i;j++)
        {
            printf("*");
        }
    printf("\n");
    }
    return 0;
}