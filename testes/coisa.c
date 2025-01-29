#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int *result = malloc(sizeof(int) * 2);
    if (numsSize == 2) {
        result[0] = 0;
        result[1] = 1;
        return result;
    }
        
    for (int i = 0; i < numsSize - 1; i++) {
        int num1 = nums[i];
        if (num1 <= target) {
            for (int j = i + 1; j < numsSize; j++) {
                if (num1 + nums[j] == target) {
                    result[0] = i;
                    result[1] = j;
                    return result;
                }
            }
        }
    }
    return result;
}

int main()
{
    int nums[] = {2,7,11,15};
    int x = 10;
    int *result = twoSum(nums, 5, 9, &x);
    printf("%d\n", result[0]);
    printf("%d\n", result[1]);
    return 0;
}


