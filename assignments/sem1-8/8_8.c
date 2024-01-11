#include<stdio.h>

void reorder(int A[], int n)
{
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        if (A[i] != 0) 
        {
            A[k++] = A[i];
        }
    }
    for (int i = k; i < n; i++) 
    {
        A[i] = 0;
    }
}

int main()
{
    int a[] = {6, 0, 8, 2, 3, 0, 4, 0, 1};
    int n = sizeof(a)/sizeof(a[0]);
    reorder(a,n);
    for(int j = 0; j < n; j++)
    {
        printf("%d ",a[j]);
    }
    return 0;
}
