#include<stdio.h>
int f(int a, int b)
{
    if (a>b)
    {
        return 0;
    }
    if (a%2==0)
    {
        return a+f(a+2,b);
    }
    return f(a+1,b);
}
int main()
{
    printf("%d",f(2,20));
}