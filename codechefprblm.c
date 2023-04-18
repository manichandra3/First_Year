#include <stdio.h>
#include <string.h>

int checkFeedback(char *feedback)
{
    int len = strlen(feedback);
    for (int i = 0; i < len - 2; i++)
    {
        if (feedback[i] == '0' && feedback[i + 1] == '1' && feedback[i + 2] == '0')
        {
            return 1;
        }
        if (feedback[i] == '1' && feedback[i + 1] == '0' && feedback[i + 2] == '1')
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    int T;
    scanf("%d", &T);
    char feedback[100000];
    for (int i = 0; i < T; i++)
    {
        scanf("%s", feedback);
        if (checkFeedback(feedback))
        {
            printf("Good\n");
        }
        else
        {
            printf("Bad\n");
        }
    }
    return 0;
}
