/*
Given an unsorted array of integers, write a program using a function to find the median
element using the quick sort algorithm. If the array has an even number of elements, return
the average of the two middle elements.
For example:

Given unsorted array-
7, 2, 5, 1, 9, 3

Expected output-
1, 2, 3, 5, 7, 9
The median element of the array is 5 (as there are an odd number of elements).
 */

#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int low, int high) 
{
    int pivot = arr[high];
    int i = (low + 1);
    int j = high;
    do {
        if (arr[i] < pivot) 
        {
            i++;
        }
        if (arr[j] > pivot) 
        {
            j--;
        }
        if (i < j) 
        {
            swap(&arr[i], &arr[j]);
        }
    } while (i < j);
    swap(&arr[low], &arr[j]);
    return j;
}

void quickSort(int *arr, int low, int high) 
{
    if (low < high) 
    {
        int pi = partition(arr, low, high);
  
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

double median(int *arr, int n) 
{
    quickSort(arr, 0, n - 1);
    if (n % 2)
        return (double)arr[n / 2];
    else
        return (double)(arr[n / 2 - 1] + arr[n / 2]) / 2.0;
}

int main() 
{
    printf("Enter the size of the array:");
    int n;
    scanf("%d", &n);
    int *array = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        printf("Enter the %d element:", i + 1);
        scanf("%d", &array[i]);
    }
    printf("%f\n", median(array, n));
    
    free(array);

    return 0;
}
