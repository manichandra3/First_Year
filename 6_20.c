#include<stdio.h>
int digitsum(int num)
{
    if (num == 0)
    {
        return 0;
    }
    return num%10+digitsum(num/10);
}
int main()
{
    printf("%d",digitsum(1234));
}