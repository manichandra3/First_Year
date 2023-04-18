#include<stdio.h>
int f(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return 1+f(n/10);
}
int main()
{
    printf("%d",f(22239));
}