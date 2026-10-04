#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void backtrack(char **result, int *returnSize, char *current, int open, int close, int max) {
    if (open == max && close == max) {
        result[*returnSize] = (char *)malloc((2 * max + 1) * sizeof(char));
        strcpy(result[*returnSize], current);
        (*returnSize)++;
        return;
    }
    if (open < max) {
        char *newCurrent = (char *)malloc(strlen(current) + 2);
        strcpy(newCurrent, current);
        strcat(newCurrent, "(");
        backtrack(result, returnSize, newCurrent, open + 1, close, max);
        free(newCurrent);
    }
    if (close < open) {
        char *newCurrent = (char *)malloc(strlen(current) + 2);
        strcpy(newCurrent, current);
        strcat(newCurrent, ")");
        backtrack(result, returnSize, newCurrent, open, close + 1, max);
        free(newCurrent);
    }
}

char** generateParenthesis(int n, int* returnSize) {
    *returnSize = 0;
    char **result = (char **)malloc(sizeof(char *) * 1430); // Maximum number of combinations for n=8
    backtrack(result, returnSize, "", 0, 0, n);
    return result;
}