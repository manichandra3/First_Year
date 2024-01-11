//
// Created by Mani Chandra Ganapathri on 13/06/23.
//
/*
Given an array arr of positive integers sorted in a strictly increasing order, and an
integer k. Return the kth positive integer that is missing from this array.

Given input array-
Input: arr = [2,3,4,7,11], k=5

Output: 9
Hint: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing
positive integer is 9.
 */
#include<stdio.h>
int binarySearch(int arr[], int l, int r, int x)
{
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;

        if (arr[mid] < x)
            l = mid + 1;
        else
            r = mid - 1;
    }

    return 0;
}

int main()
{
    int n, k;
    printf("Enter the size and the position of the ith missing positive integer to find: ");
    scanf("%d %d", &n, &k);

    int arr1[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr1[i]);
    }

    int count = 0;
    int a;
    for (int i = 0; i < n+k; i++)
    {
        if (!(binarySearch(arr1, 0, n - 1, i + 1)))
        {
            a=i+1;
            count++;
        }
        if (count == k)
        {
            break;
        }
    }

    printf("%d\n", a+1);
    return 0;
}
