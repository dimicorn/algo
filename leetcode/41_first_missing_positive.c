#include <stdio.h>
#include <stdlib.h>

int firstMissingPositive(int* nums, int numsSize) {
    int n = numsSize;
    int contains = 1;

    for (int i = 0; i < n; ++i) {
        if (nums[i] == 1)
            contains = 0;
    
        if (nums[i] <= 0 || nums[i] > n)
            nums[i] = 1;
    }   

    if (contains == 1)
        return 1;

    for (int i = 0; i < n; ++i) {
        int value = abs(nums[i]);
        if (value == n)
            nums[0] = -abs(nums[0]);
        else
            nums[value] = -abs(nums[value]);
    }   

    for (int i = 1; i < n; ++i)
        if (nums[i] > 0)
            return i;

    if (nums[0] > 0)
        return n;

    return n+1;
}

int main() {
    int nums[3] = {1, 2, 0};
    printf("%d\n", firstMissingPositive(nums, 3));
    return 0;
}
