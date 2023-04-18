#include<stdio.h>

double median(int a[], int size)
{
    double med;
    if (size%2 != 0)
    {
        med = a[(size-1)/2];
    }
    if (size%2 == 0)
    {
        med = (a[(size)/2 - 1] + a[size/2])/2;
    }
    return med;
}

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

void selectionSort(int arr[], int n) 
{ 
    int i, j, min_idx; 
    for (i = 0; i < n-1; i++)
    {
        min_idx = i; 
        for (j = i+1; j < n; j++)
        {
          if (arr[j] < arr[min_idx]) 
              min_idx = j;
        }
        if (min_idx!=i)
            swap(&arr[min_idx], &arr[i]);
    }
} 

int main()
{
    int len1,len2;
    double med;
    printf("enter the sizes of both the arays: ");
    scanf("%d%d",&len1,&len2);
    int arr1[len1],arr2[len2];
    printf("Enter the elements of the first array:\n");
    for (int i = 0; i < len1; i++)
    {
        scanf("%d",&arr1[i]);
    }
    printf("Enter the elements of the second array:\n");
    for(int i = 0; i < len2; i++)
    {
        scanf("%d",&arr2[i]);
    }
    int a[len1+len2];
    for (int i = 0; i < len1+len2; i++)
    {
        if (i < len1)
        {
            a[i] = arr1[i];
        }
        else if (i >= len1 && i < len1+len2)
        {
            a[i] = arr2[i - len1];
        }
    }
    selectionSort(a,len1+len2);
    med = median(a,len1+len2);
    printf("%f",med);
}