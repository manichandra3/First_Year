#include<stdio.h>
#include<limits.h>

int max_subarray(int a[],int size)
{
    int max = INT_MIN;
    int sum = 0;

    for (int i = 0; i < size; i++)
    {
        sum = sum + a[i];
        if(max < sum)
        {
            max = sum;
        }
        if(sum < 0)
        {
            sum = 0;
        }
    }
    return max;
}

int main()
{
    int a[] = {2,3,-1,6};
    int size = 4;

    int max = max_subarray(a,size);
    printf("%d",max);
}