#include<stdio.h>
int fib(int n)
{
    if (n == 1 || n == 2)
    {
        return n-1;
    }
    else
    { 
        return fib(n-2)+fib(n-1);
    }
}
int main()
{
    printf("%d",fib(5));
}