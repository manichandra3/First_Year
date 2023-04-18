#include<stdio.h>
int bestTeamScore(int* scores, int scoresSize, int* ages, int agesSize)
{
    int i,j,t;
    int age[];
    for (i = 0; i < scoreSize-1; i++)
    {
        for (j = i+1; j < socreSize; j++)
        {
            if (age[i]<age[j] && scores[i]>scores[j])
            {
                t = age[i];
                age[i] = age[j];
                age[i] = t;
            }
        }
    }
    return age;
}
int main()
{
    int scores[] = {1,3,5,10,15};
    int ages[] = {1,2,3,4,5};
    bestTeamScore(scores,5,ages,5);
}