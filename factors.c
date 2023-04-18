#include<stdio.h>
int main()
{
    int i,n;
    printf("Enter any number:");
    scanf("%d",&n);
    printf("The factors of %d are:\n",n);
    for (i=1;i<=9;i++)
    {
        if (n%i==0)
        {
            printf("%d\n",i);
        }
    }
}