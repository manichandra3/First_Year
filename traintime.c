#include <stdio.h>

int main()
{
    int T, N;

    printf("Enter the value of T:\n");
    scanf("%d", &T);

    for (int i = 0; i < T; i++)
    {
        printf("Enter the value of N:\n");
        scanf("%d", &N);

        int p[N - 1];

        printf("Enter the elements of P:\n");
        for (int i = 0; i < N - 1; i++)
        {
            scanf("%d", &p[i]);
        }

        int a_count[N];
        *a_count = 0;
        for (int i = 1; i < N; i++)
        {
            a_count[i] = a_count[i - 1] + p[i - 1];
        }

        int b_count[N];
        b_count[0] = p[0];
        b_count[1] = 2 * p[0];

        for (int i = 2; i < N; i++)
        {
            if (b_count[i - 1] < a_count[i])
            {
                b_count[i] = a_count[i] + p[i - 1];
            }
            else
            {
                b_count[i] = b_count[i - 1] + p[i - 1];
            }
        }

        printf("%d\n", b_count[N - 1]);
    }

    return 0;
}
