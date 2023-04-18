#include <stdio.h>
int main()
{
    int num, n, rem, sum = 0;
    printf("Enter any number: ");
    scanf("%d", &num);
    n = num;
    while (num != 0)
    {
        rem = num % 10;
        sum += rem * rem * rem;
        num = num / 10;
    }
    if (sum == n)
    {
        printf("%d is an Armstrong Number!\n", n);
    }
    else
    {
        printf("%d is not an Armstrong Number!\n", n);
    }
    main();
}