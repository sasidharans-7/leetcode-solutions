#include <stdio.h>
#include <stdlib.h>

void backtrack(int* candidates, int candidatesSize, int target, int start, int* current, int currentSize, int** result, int* resultSize, int** returnColumnSizes) {
    if (target == 0) {
        result[*resultSize] = (int*)malloc(currentSize * sizeof(int));
        memcpy(result[*resultSize], current, currentSize * sizeof(int));
        (*returnColumnSizes)[*resultSize] = currentSize;
        (*resultSize)++;
        return;
    }
    if (target < 0) {
        return;
    }
    for (int i = start; i < candidatesSize; i++) {
        current[currentSize] = candidates[i];
        backtrack(candidates, candidatesSize, target - candidates[i], i, current, currentSize + 1, result, resultSize, returnColumnSizes);
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    int** result = (int**)malloc(150 * sizeof(int*));
    *returnColumnSizes = (int*)malloc(150 * sizeof(int));
    *returnSize = 0;
    int* current = (int*)malloc(target * sizeof(int));
    backtrack(candidates, candidatesSize, target, 0, current, 0, result, returnSize, returnColumnSizes);
    free(current);
    return result;
}