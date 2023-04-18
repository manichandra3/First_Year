#include<stdio.h>
int p(int x, int n)
{
    int a=1,i;
    if (i == 0)
    {
        return 1;
    }
    else
    {
        for (i = n; i = 1; i--)
        {
            a *= x;
        }
        return a;
    }
}
int main()
{
    printf("%d",p(3,6));
}