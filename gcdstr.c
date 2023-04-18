#include<stdio.h>
#include<strings.h>

char * gcdOfStrings(char * str1, char * str2)
{
    void printArray(int arr[], int n) 
    {
        int i;
        for (i=0; i<n; i++)
            printf("%d ", arr[i]);
            printf("\n");
    }

    void swap(int arr[], int i, int j) 
    {
        while (i < j) 
        {
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
            i++; j--;
        }
    }

    void leftRotate(int arr[], int n, int k) 
    {
        k = k % n;
        swap(arr, 0, k-1);
        swap(arr, k, n-1);
        swap(arr, 0, n-1);
    }

    void rightRotate(int arr[], int n, int k) 
    {
        k = k % n;
        swap(arr, 0, n-k-1);
        swap(arr, n-k, n-1);
        swap(arr, 0, n-1);
    }
}