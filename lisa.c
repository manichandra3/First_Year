#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int *arr = malloc(n * sizeof(int));
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }

    int *lisa = malloc(n * sizeof(int));
    int max_length = 1;

    for (int i = 0; i < n; i++) 
    {
        lisa[i] = 1;
    }

    for (int i = 1; i < n; i++) 
    {
        for (int j = 0; j < i; j++) 
        {
            if (arr[i] > arr[j] && lisa[i] < lisa[j] + 1) 
            {
                lisa[i] = lisa[j] + 1;
            }
        }
        if (lisa[i] > max_length) 
        {
            max_length = lisa[i];
        }
    }

    printf("%d",max_length);

    free(arr);
    free(lisa);

    return 0;
}
