#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) 
{
    char* prefix = "";
    int index = 0; 
    
    // Iterate through the first string in the array
    for (int i = 0; i < strlen(strs[0]); i++) 
    {
        char c = strs[0][i];
        
        // Check if the current character exists in all strings
        for (int j = 1; j < strsSize; j++) 
        {
            if (index >= strlen(strs[j]) || strs[j][index] != c) 
            {
                return prefix;
            }
        }
        
        // Add the character to the prefix
        char* temp = (char*)malloc((i+2) * sizeof(char));
        strncpy(temp, strs[0], i+1);
        temp[i+1] = '\0';
        prefix = temp;
        
        index++;
    }
    
    return prefix;
}

int main() {
    char* strs[] = {"flower", "flow", "flight"};
    int strsSize = 3;

    char* prefix = longestCommonPrefix(strs, strsSize);

    printf("The longest common prefix is: %s\n", prefix);

    return 0;
}