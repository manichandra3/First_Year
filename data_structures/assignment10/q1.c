#include <stdio.h>
#include<stdlib.h>

int mergeSort(int arr[], int l, int r);
int merge(int arr[], int l, int m, int r);

int partition(int arr[], int low, int high);
int quickSort(int arr[], int low, int high);

int insertionSort(int arr[], int n);
int selectionSort(int arr[], int n);
int bubbleSort(int arr[], int n);

void swap(int *a, int *b);

void print(int A[], int size);

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        printf("Enter the size of the array: ");
        scanf("%d", &n);
        int arr[n];

        for (int i = 0; i < n; i++)
        {
            printf("Enter element %d: ", i + 1);
            scanf("%d", &arr[i]);
        }

        printf("Original array: ");
        print(arr, n);

        int swaps;

        printf("Menu\n");
        printf("1. Merge Sort\n");
        printf("2. Quick Sort\n");
        printf("3. Insertion Sort\n");
        printf("4. Selection Sort\n");
        printf("5. Bubble Sort\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                swaps = mergeSort(arr, 0, n - 1);
                printf("Sorted array using Merge Sort: ");
                print(arr, n);
                printf("Number of swaps: %d\n", swaps);
                break;

            case 2:
                swaps = quickSort(arr, 0, n - 1);
                printf("Sorted array using Quick Sort: ");
                print(arr, n);
                printf("Number of swaps: %d\n", swaps);
                break;

            case 3:
                swaps = insertionSort(arr, n);
                printf("Sorted array using Insertion Sort: ");
                print(arr, n);
                printf("Number of swaps: %d\n", swaps);
                break;

            case 4:
                swaps = selectionSort(arr, n);
                printf("Sorted array using Selection Sort: ");
                print(arr, n);
                printf("Number of swaps: %d\n", swaps);
                break;

            case 5:
                swaps = bubbleSort(arr, n);
                printf("Sorted array using Bubble Sort: ");
                print(arr, n);
                printf("Number of swaps: %d\n", swaps);
                break;

            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}

int mergeSort(int arr[], int l, int r)
{
    int swaps = 0;

    if (l < r)
    {
        int m = l + (r - l) / 2;

        swaps += mergeSort(arr, l, m);
        swaps += mergeSort(arr, m + 1, r);

        swaps += merge(arr, l, m, r);
    }

    return swaps;
}

int merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int swaps = 0;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
            swaps += n1 - i;  // Count the number of swaps
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    return swaps;
}

int quickSort(int arr[], int low, int high)
{
    int swaps = 0;

    if (low < high)
    {
        int pi = partition(arr, low, high);

        swaps += quickSort(arr, low, pi - 1);
        swaps += quickSort(arr, pi + 1, high);
    }

    return swaps;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

int insertionSort(int arr[], int n)
{
    int swaps = 0;

    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
            swaps++;
        }

        arr[j + 1] = key;
    }

    return swaps;
}

int selectionSort(int arr[], int n)
{
    int swaps = 0;

    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        if (minIndex != i)
        {
            swap(&arr[i], &arr[minIndex]);
            swaps++;
        }
    }

    return swaps;
}

int bubbleSort(int arr[], int n)
{
    int swaps = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                swaps++;
            }
        }
    }

    return swaps;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print(int A[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}
