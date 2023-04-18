#include <stdio.h>

void selectionSort(int arr[], int size);
void removeDuplicates(int arr[], int *size);

int main()
{
    int arr[] = {1, 2, 3, 2, 1, 4, 2, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int freq[size];

    selectionSort(arr, size);
    printf("Frequency of each element:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d: %d\n", arr[i], freq[i]);
    }

    removeDuplicates(arr, &size);

    for (int i = 0; i < size; i++)
    {
        int count = 1;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }
        freq[i] = count;
    }

    printf("Frequency of each element:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d: %d\n", arr[i], freq[i]);
    }

    return 0;
}

void selectionSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
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
