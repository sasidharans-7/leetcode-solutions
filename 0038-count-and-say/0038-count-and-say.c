#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* countAndSay(int n) {
    if (n == 1) {
        char* result = (char*)malloc(2 * sizeof(char));
        result[0] = '1';
        result[1] = '\0';
        return result;
    }

    char* prev = countAndSay(n - 1);
    int len = strlen(prev);
    char* result = (char*)malloc((2 * len + 1) * sizeof(char));
    int i = 0, j = 0, count = 1;

    while (i < len) {
        if (i + 1 < len && prev[i] == prev[i + 1]) {
            count++;
        } else {
            result[j++] = count + '0';
            result[j++] = prev[i];
            count = 1;
        }
        i++;
    }

    result[j] = '\0';
    free(prev);
    return result;
}