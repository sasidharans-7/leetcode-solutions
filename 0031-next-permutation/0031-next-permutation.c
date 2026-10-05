#include <stdio.h>
#include <stdlib.h>

void nextPermutation(int* nums, int numsSize) {
    if (numsSize <= 1) return;

    int i = numsSize - 2;
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        i--;
    }

    if (i >= 0) {
        int j = numsSize - 1;
        while (nums[j] <= nums[i]) {
            j--;
        }
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    for (int start = i + 1, end = numsSize - 1; start < end; start++, end--) {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
    }
}