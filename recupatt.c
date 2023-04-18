#include<stdio.h>
void f1(int num)
{
    if (num == 0)
        return;
    printf("* ");
    f1(num - 1);
}
void f2(int n, int i)
{
    if (n==0)
        return;
    f1(i);
    printf("\n");
    f2(n-1, i+1);
}
int main()
{
    int n = 5;
    f2(n, 1);
    return 0;
}