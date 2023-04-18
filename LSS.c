#include<stdio.h>
int lengthOfLongestSubstring(char * s)
{
    int count = 0;
    int a[sizeof(s)];
    for (int i = 0; i < sizeof(s); i++)
    {
        for (int j = 0; j < sizeof(s); j++)
        {
            if (a[j] != s[i])
            {
                a[j] = s[i];
                count++;
            }
            else 
            {
                break;
            }
        }
    }
    return count;
}
int main()
{
    char s = "abcabcbb";
    printf("%c",lengthOfLongestSubstring(&s));
}