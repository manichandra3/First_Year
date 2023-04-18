#include<stdio.h>
#include<string.h>

typedef struct 
{
    char word[1000];
    int frequency;
} WordFreq;

//removes non english characters...
void RemoveNonEnglish(char arr[], int l)
{
    for (int i = 0; i < l; i++)
    {
        if (arr[i] < 'A' || arr[i] > 'Z')
        {
            arr[i] = ' '; // Replace non-English characters with space
        }
    }
}

//converts to uppercase...
void Uppercase(char arr[], int l)
{
    for (int i = 0; i < l; i++)
    {
        if (arr[i] >= 'a' && arr[i] <= 'z')
        {
            arr[i] -= 32; // Convert lowercase letters to uppercase
        }
    }
}

int main()
{
    char para[1000], p[500][1000], ptr1[500][1000];
    int count = 0, c = 0, i, j = 0, k, space = 0;

    printf("Enter the string:\n");
    fgets(para, sizeof(para), stdin); // Use fgets to read the string

    int len = strlen(para);
    printf("string length is %d\n", len);

    Uppercase(para, len);
    RemoveNonEnglish(para, len);

    for (i = 0; i< len; i++) {
        if ((para[i] == ' ')||(para[i] == ',' && para[i+1] == ' ')) {
            space++;
        }
    }

    for (i = 0, j = 0, k = 0;j < len;j++) {
        if ((para[j] == ' ')||(para[j] == 44)||(para[j] == 46)) {    
            p[i][k] = '\0';
            i++;
            k = 0;
        } else {
            p[i][k++] = para[j];
        }
    }

    k = 0;
    WordFreq wf[space+1];

    for (i = 0;i <= space;i++) {
        for (j = 0;j <= space;j++) {
            if (i == j) {
                strcpy(ptr1[k], p[i]);
                k++;
                count++;
                break;
            } else {
                if (strcmp(ptr1[j], p[i]) != 0)
                    continue;
                else
                    break;
            }
        }
    }

    for (i = 0;i < count;i++) {
        strcpy(wf[i].word, ptr1[i]);
        wf[i].frequency = 0;
        for (j = 0;j <= space;j++) {
            if (strcmp(ptr1[i], p[j]) == 0)
                wf[i].frequency++;
        }
    }

    WordFreq temp;
    for (i = 0; i < count - 1; i++) {
        for (j = i + 1; j < count; j++) {
            if (wf[i].frequency < wf[j].frequency) {
                temp = wf[i];
                wf[i] = wf[j];
                wf[j] = temp;
            }
        }
    }

    for (i = 0;i < count;i++) {
        printf("%s -> %d times\n", wf[i].word, wf[i].frequency);
    }

    //command line interface...
    char targ[50];
    int length;
    printf("Enter word (enter q to exit!): ");
    while (fgets(targ, sizeof(targ), stdin))
    {
        length = strlen(targ);
        if (targ[length - 1] == '\n') {
            targ[length - 1] = '\0'; // Remove newline character
        }
        if (strcmp(targ, "q") == 0)
        {
            break; // Exit if user enters 'q'
        }
        else
        {
            int freq = 0;
            for (i = 0; i <= space; i++)
            {
                if (strcmp(targ, p[i]) == 0)
                {
                    freq++;
                }
            }
            printf("The word '%s' appears '%d' times in the paragraph",targ,freq);
        }
    }
}
