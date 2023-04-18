#include<stdio.h>
int main()
{
    int i=1,n,j=0;
    printf("Enter any number:");
    scanf("%d",&n);
    for (i=1;i<=9;i++)
    {
        j = i * n;
        printf("%d x %d = %d\n", n, i, j);
    }
}