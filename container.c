#include<stdio.h>
int maxArea(int* height, int heightSize)
{
    int i,j,max=0;
    int area;
    
    for (i = 0; i < heightSize; i++)
    {
        for (j = 1; j < heightSize; j++)
        {
            int min_height = height[i]<height[j]?height[i]:height[j];
            area = (j-i) * min_height;
            max = max < area ? area : max;
        }
    }
    return max;
}
int main()
{
    
}
