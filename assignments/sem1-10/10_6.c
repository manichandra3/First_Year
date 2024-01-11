#include <stdio.h>
#include <string.h>

int main() {
    char str[1000];
    printf("Enter a string: ");
    fgets(str, 1000, stdin);

    char *words[100];
    int wordCount = 0;
    char *token = strtok(str," ");
    while (token != NULL) {
        words[wordCount++] = token;
        token = strtok(NULL, " ");
    }

    printf("Reversed string:");
    for (int i = wordCount - 1; i >= 0; i--) {
        printf("%s ", words[i]);
    }


    return 0;
}