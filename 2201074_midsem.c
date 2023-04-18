#include<stdio.h>
#include<math.h>
//gives the number of digits for additional checking.
int digits(int num)
{
    if (num == 0)
    {
        return 0;
    }
    return 1+digits(num/10);
}
//returns the reverse of the number.
int reverse(int num)
{
    if (num == 0)
    {
        return 0;
    }
    return num%10*pow(10,digits(num)-1)+reverse(num/10);
}
//gives the reverse of the mirrored value.
int mirror(int num)
{
    int rem,mir;
    while (num != 0)
    {
        rem = num%10;
        if (rem == 6 || rem == 3 || rem == 4 || rem == 7 || rem == 9)
        {
            return 2;
        }
        if (rem == 0)
        {
            rem = 0;
        }
        else
        {
            if (rem == 1)
            {
                rem = 1;
            }
            else
            {
                if (rem == 2)
                {
                    rem = 5;
                }
                else
                {
                    if (rem == 5)
                    {
                        rem = 2;
                    }
                    else
                    {
                        if (rem == 8)
                        {
                            rem = 8;
                        }
                    }
                }
            }
        }
        return rem + mirror(num/10)*10;
    }
}
//returns 1 if the value is prime and 0 if non prime.
int isprime(int n) 
{
    double sqrt_n = sqrt(n);
    for (int i = 2; i <= sqrt_n; i++)
        if (n % i == 0) return 0;
    return 1;
}
//checks and prints the alpha numbers.
int alpha(int a, int b)
{
    if (a==b)
    {
        return 0;
    }
    if (isprime(a) == 1 && isprime(reverse(a)) == 1 && isprime(mirror(a)) == 1 && isprime(reverse(mirror(a))) == 1 && digits(a)==digits(mirror(a)))
    {
        printf("%d\n",a);
    }
    alpha(a+1,b);
}
int main()
{
    alpha(100,200);
    printf("%d",mirror(123));
}