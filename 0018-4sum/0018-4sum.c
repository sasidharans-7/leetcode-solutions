int cmp(const void *a, const void *b) {
    int x = *(int *)a, y = *(int *)b;
    return (x > y) - (x < y);
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int cap = 16;
    int **res = malloc(cap * sizeof(int *));
    *returnColumnSizes = malloc(cap * sizeof(int));
    *returnSize = 0;

    for (int i = 0; i < numsSize - 3; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        for (int j = i + 1; j < numsSize - 2; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;
            int l = j + 1, r = numsSize - 1;
            while (l < r) {
                long long s = (long long)nums[i] + nums[j] + nums[l] + nums[r];
                if (s < target) l++;
                else if (s > target) r--;
                else {
                    if (*returnSize == cap) {
                        cap *= 2;
                        res = realloc(res, cap * sizeof(int *));
                        *returnColumnSizes = realloc(*returnColumnSizes, cap * sizeof(int));
                    }
                    int *q = malloc(4 * sizeof(int));
                    q[0] = nums[i]; q[1] = nums[j]; q[2] = nums[l]; q[3] = nums[r];
                    res[*returnSize] = q;
                    (*returnColumnSizes)[*returnSize] = 4;
                    (*returnSize)++;
                    l++; r--;
                    while (l < r && nums[l] == nums[l - 1]) l++;
                    while (l < r && nums[r] == nums[r + 1]) r--;
                }
            }
        }
    }
    return res;
}