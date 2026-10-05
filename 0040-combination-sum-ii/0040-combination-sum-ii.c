#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void backtrack(int* candidates, int candidatesSize, int target, int start, int* combination, int combinationSize, int** result, int* returnSize, int** returnColumnSizes) {
    if (target == 0) {
        int* newCombination = (int*)malloc(combinationSize * sizeof(int));
        memcpy(newCombination, combination, combinationSize * sizeof(int));
        result[*returnSize] = newCombination;
        (*returnColumnSizes)[*returnSize] = combinationSize;
        (*returnSize)++;
        return;
    }
    if (target < 0) {
        return;
    }
    for (int i = start; i < candidatesSize; i++) {
        if (i > start && candidates[i] == candidates[i - 1]) {
            continue; // Skip duplicates
        }
        combination[combinationSize] = candidates[i];
        backtrack(candidates, candidatesSize, target - candidates[i], i + 1, combination, combinationSize + 1, result, returnSize, returnColumnSizes);
    }
}

int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    qsort(candidates, candidatesSize, sizeof(int), (int (*)(const void *, const void *))strcmp);
    *returnSize = 0;
    int** result = (int**)malloc(1000 * sizeof(int*));
    *returnColumnSizes = (int*)malloc(1000 * sizeof(int));
    int* combination = (int*)malloc(candidatesSize * sizeof(int));
    backtrack(candidates, candidatesSize, target, 0, combination, 0, result, returnSize, returnColumnSizes);
    free(combination);
    return result;
}