/*
Given an unsorted array of n elements, write a C program to find two elements in the
array such that their sum is equal to given element K. Note that the time complexity of
your algorithm should be O(nlogn).
 */
#include<stdio.h>
int binarySearch(int arr[], int l, int r, int x)
{
    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] < x)
            l = mid + 1;
        else
            r = mid - 1;
    }

    return -1;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
void printArray(int *arr)
{
    int len = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0; i < len; i++)
        printf("%d",arr[i]);
}
int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printArray(arr);
    int x;
    printf("Enter your target: ");
    scanf("%d", &x);
    int target = 0;
    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n - 1; i++)
    {
        target = x - arr[i];
        int pairIndex = binarySearch(arr, i + 1, n - 1, target);
        if (pairIndex != -1)
        {
            printf("%d + %d = %d\n", arr[i], arr[pairIndex],x);
            break;
        }
    }
    return 0;
}
