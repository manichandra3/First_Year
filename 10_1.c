#include <stdio.h>

int main() 
{
    char str[100];
    printf("Enter a string: ");
    fgets(str, 100, stdin);
    int i = 0;
    while (str[i] != '\0') 
    {
        printf("Address of '%c': %p\n", str[i], &str[i]);
        i++;
    }

    return 0;
}
