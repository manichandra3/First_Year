#include<stdio.h>

 int check(int arr[], int size,int target)
 {
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            count++;
        }
    }

    if (count == 0)
    {
        return 0;
    }
    return count;
 }

int main()
{
    int a[] = {1,4,6,7,7};
    int count  = check(a,5,7);
    int len = sizeof(a)/sizeof(a[0]);

    if (check(a,5,7) == 0)
    {
        printf("The target element is not in the array.");
    }
    if (count > len/2.0)
    {
        printf("Y\n");
    }
    else
    {
        printf("N\n");
    }
    
    return 0;
}