#include<stdio.h>

#define L1(x,y) (x>y)
#define L2(x,y) (x<y)

int main()
{
    int a,b;
    printf("Enter first num a:");
    scanf("%d",&a);
    printf("\n");
    printf("Enter the second num b:");
    scanf("%d",&b);
    printf("\n");
    if(L1(a,b))
    {
        printf("a>b");
    }
    else if(L2(a,b))
    {
        printf("a<b");
    }
}