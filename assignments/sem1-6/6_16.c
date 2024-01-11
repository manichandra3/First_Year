#include<stdio.h>
int p(int x, int n)
{
    if (n==0) 
    {
        return 1;
    }
    else
    {
        return x*p(x,n-1);
    }
    
}
int main()
{
    printf("%d",p(3,2));
}