#include<stdio.h>
#include<math.h>
int digits(int num)
{
    if (num == 0)
    {
        return 0;
    }
    return 1+digits(num/10);
}
int reverse(int num)
{
    if (num == 0)
    {
        return 0;
    }
    return num%10*pow(10,digits(num)-1)+reverse(num/10);
}
int main()
{
    printf("%d",reverse(2343));
}