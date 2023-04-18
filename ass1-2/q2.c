#include <stdio.h>

void displayMatrix(int matrix[][3], int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int rows, cols;
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &rows, &cols);

    int matrix[rows][cols];
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    int sum = 0;
    printf("Matrix:\n");
    displayMatrix(matrix, rows);
    printf("\n");
    printf("Diagonal Elements:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (i == j)
            {
                printf("%d ", matrix[i][j]);
                sum += matrix[i][j];
            }
        }
    }
    printf("\nSum of Diagonal Elements: %d\n", sum);
    printf("\n");

    if (rows != 3 || cols != 3)
    {
        printf("Inverse Matrix is not possible for a matrix other than 3x3.\n");
        return 0;
    }

    int det = 0;
    for (int i = 0; i < 3; i++)
    {
        det += (matrix[0][i] * (matrix[1][(i + 1) % 3] * matrix[2][(i + 2) % 3] - matrix[1][(i + 2) % 3] * matrix[2][(i + 1) % 3]));
    }
    if (det == 0)
    {
        printf("Inverse doesn't exist\n");
    }
    else
    {
        printf("Determinant: %d\n", det);
        int adj[3][3];
        int inv[3][3];
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                adj[i][j] = (matrix[(j + 1) % 3][(i + 1) % 3] * matrix[(j + 2) % 3][(i + 2) % 3]) - (matrix[(j + 1) % 3][(i + 2) % 3] * matrix[(j + 2) % 3][(i + 1) % 3]);
                inv[i][j] = adj[i][j] / det;
            }
        }
        printf("\nAdjoint Matrix:\n");
        displayMatrix(adj, 3);
        printf("\nInverse Matrix:\n");
        displayMatrix(inv, 3);
    }

    return 0;
}
