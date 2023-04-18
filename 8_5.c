#include<stdio.h>

void swap(int* a, int* b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void selectionsort(int a[], int size)
{
    int min_index;
    for(int i = 0; i < size-1; i++)
    {
        min_index = i;
        for(int j = i+1; j < size; j++)
        {
            if(a[j] < a[min_index])
            {
                min_index = j;
            }
        }
        if(min_index != i)
        {
            swap(&a[i], &a[min_index]);
        }
    }
}

int main()
{
    int a[] = {2,4,1,5,3};
    int size = sizeof(a)/sizeof(a[0]);
    
    selectionsort(a,size);
    for (int i = 0; i < size; i++)
    {
        printf("%d",a[i]);
    }
}