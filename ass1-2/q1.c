#include <stdio.h>
#include <stdlib.h>
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int *counter(int arr[], int s)
{
    int *freq = (int *)malloc(s * sizeof(int));
    for (int i = 0; i < s; i++)
    {
        int count = 1;
        for (int j = i + 1; j < s; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }
        freq[i] = count;
    }
    return freq;
}

void removeDuplicates(int arr[], int *size)
{
    int i, j, k;
    for (i = 0; i < *size; i++)
    {
        for (j = i + 1; j < *size; j++)
        {
            if (arr[i] == arr[j])
            {
                for (k = j; k < *size - 1; k++)
                {
                    arr[k] = arr[k + 1];
                }
                (*size)--;
                j--;
            }
        }
    }
}

int main()
{
    int S;
    printf("size of the array:");
    scanf("%d", &S);
    int arr[S];
    for (int i = 0; i < S; i++)
    {
        scanf("%d", &arr[i]);
    }
    removeDuplicates(arr, &S);
    int *freq = counter(arr, S + 1);
    for (int i = 0; i < S; i++)
    {
        printf("The frequency of %d is %d\n", arr[i], freq[i]);
    }
    free(freq);
    return 0;
}
