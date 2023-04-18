#include <stdio.h>

int main()
{
    int m, n;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &m, &n);
    int a[m][n];
    // input
    printf("Enter the elements of the matrix: \n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    int tar;
    printf("Enter the target element: ");
    scanf("%d", &tar);
    // search
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == tar)
            {
                printf("The row is %d and the column is %d: ", i, j);
                break;
            }
        }
    }
    int neighbors[8];
    int index = 0;
    for (int i = m - 1; i <= m + 1; i++)
    {
        for (int j = n - 1; j <= n + 1; j++)
        {
            if (i >= 0 && i < 3 && j >= 0 && j < 4 && (i != m || j != n))
            {
                neighbors[index] = a[i][j];
                index++;
            }
        }
    }
    // sort
    for (int i = 0; i < 7; i++)
    {
        for (int j = i + 1; j < 8; j++)
        {
            if (neighbors[i] > neighbors[j])
            {
                int temp = neighbors[i];
                neighbors[i] = neighbors[j];
                neighbors[j] = temp;
            }
        }
    }
    // print the neighboring elements
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d", a[i][j]);
        }
    }
    return 0;
}
