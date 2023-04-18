#include<stdio.h>
#include<stdlib.h>
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int i,j,k;
    int* result = (int*) malloc(2 * sizeof(int));
    *returnSize = 2;
    for (i = 0; i <= numsSize; i++)
    {
        for (j = i + 1; j <= numsSize; j++)
        {
            result[0] = i;
            result[1] = j;
            k = nums[i]+nums[j];
            if (k == target)
            {
                return result;
            }
        }
    }
    return result;
}
int main() {
    int nums[] = {2, 7, 11, 15};
    int target = 13;
    int returnSize;
    int* result = twoSum(nums, sizeof(nums) / sizeof(nums[0]), target, &returnSize);
    printf("Indices: [%d, %d]\n", result[0], result[1]);
    free(result);
    return 0;
}