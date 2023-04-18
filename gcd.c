#include<stdio.h>
int main()
{
    int i,n,j,a,b,min;
    printf("Enter a:");
    scanf("%d", &a);
    printf("Enter b:");
    scanf("%d", &b);
    if (a<b)
    {
        min = a;
    }
    else
    {
        min = b;
    }
    for (i=min;i>=1;i--)
    {
        if(a%i==0 && b%i==0)
        {
            printf("%d is the GCD of %d and %d.\n", i, a, b);
            break;
        }
    }
}