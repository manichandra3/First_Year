#include <stdio.h>

void concatenateStrings(char[], char[]);
int compareStrings(char[], char[]);
int compareStringsUsingLib(char[], char[]);
int calculateStringLength(char[]);
void copyString(char[], char[]);

int main() {
    int choice;
    char str1[100], str2[100];
    
    do {
        printf("\nMenu:\n");
        printf("1. Concatenate two strings\n");
        printf("2. Compare two strings without using the strcmp function\n");
        printf("3. Compare two strings using the strcmp function\n");
        printf("4. Calculate length of a string\n");
        printf("5. Copy one string to another\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter first string: ");
                scanf("%s", str1);
                printf("Enter second string: ");
                scanf("%s", str2);
                concatenateStrings(str1, str2);
                break;
            case 2:
                printf("Enter first string: ");
                scanf("%s", str1);
                printf("Enter second string: ");
                scanf("%s", str2);
                if (compareStrings(str1, str2) == 0) {
                    printf("The strings are equal\n");
                } else {
                    printf("The strings are not equal\n");
                }
                break;
            case 3:
                printf("Enter first string: ");
                scanf("%s", str1);
                printf("Enter second string: ");
                scanf("%s", str2);
                if (compareStringsUsingLib(str1, str2) == 0) {
                    printf("The strings are equal\n");
                } else {
                    printf("The strings are not equal\n");
                }
                break;
            case 4:
                printf("Enter a string: ");
                scanf("%s", str1);
                printf("The length of the string is %d\n", calculateStringLength(str1));
                break;
            case 5:
                printf("Enter a string: ");
                scanf("%s", str1);
                copyString(str1, str2);
                printf("The copied string is %s\n", str2);
                break;
            case 6:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);
    
    return 0;
}

void concatenateStrings(char str1[], char str2[]) {
    int i, j;
    i = j = 0;
    
    while (str1[i] != '\0') {
        i++;
    }
    
    while (str2[j] != '\0') {
        str1[i] = str2[j];
        i++;
        j++;
    }
    
    str1[i] = '\0';
    printf("The concatenated string is %s\n", str1);
}

int compareStrings(char str1[], char str2[]) {
    int i;
    i = 0;
    
    while (str1[i] == str2[i]) {
        if (str1[i] == '\0' || str2[i] == '\0') {
            break;
        }
        i++;
    }
    
    if (str1[i] == '\0' && str2[i] == '\0') {
        return 0;
    } else {
        return -1;
    }
}

// Function
