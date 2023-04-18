#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
void counter(char *s, int size)
{
    int *count = (int *)malloc(1000 * sizeof(int));
    int c = 0;
    int l = 0;
    for (int i = 0; i < size; i++)
    {
        if (s[i] == ' ')
        {
            if ((c + 1) % 2 == 1 && l % 2 == 0)
            {
                int start = i - l;
                int end = i - 1;
                while (start < end)
                {
                    char temp = s[start];
                    s[start] = s[end];
                    s[end] = temp;
                    start++;
                    end--;
                }
            }
            count[c] = l;
            c++;
            l = 0;
        }
        else
        {
            l++;
        }
    }
    count[c] = l - 1;
    if ((c + 1) % 2 == 1 && l % 2 == 0)
    {
        int start = size - l - 1;
        int end = size - 2;
        while (start < end)
        {
            char temp = s[start];
            s[start] = s[end];
            s[end] = temp;
            start++;
            end--;
        }
    }

    for (int i = 0; i < c + 1; i++)
    {
        printf("%d ", count[i]);
    }
    free(count);
}

int main()
{
    char set[1000];
    fgets(set, 1000, stdin);
    int len = strlen(set);
    counter(set, len);
    printf("%s", set);
}