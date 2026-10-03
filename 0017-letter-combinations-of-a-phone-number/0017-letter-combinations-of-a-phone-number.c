/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

char** letterCombinations(char* digits, int* returnSize) {
    char *map[] = {
        "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    *returnSize = 0;

    if (digits[0] == '\0') {
        return NULL;
    }

    int len = strlen(digits);

    // Maximum possible combinations = 4^4 = 256
    char **result = malloc(256 * sizeof(char*));

    char current[5];
    current[len] = '\0';

    // Backtracking function
    void backtrack(int index) {
        if (index == len) {
            result[*returnSize] = malloc((len + 1) * sizeof(char));
            strcpy(result[*returnSize], current);
            (*returnSize)++;
            return;
        }

        int digit = digits[index] - '0';
        char *letters = map[digit];

        for (int i = 0; letters[i] != '\0'; i++) {
            current[index] = letters[i];
            backtrack(index + 1);
        }
    }

    backtrack(0);

    return result;
}