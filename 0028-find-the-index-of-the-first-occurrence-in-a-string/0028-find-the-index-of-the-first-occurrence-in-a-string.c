#include <stdio.h>
#include <string.h>

void computeLPSArray(char *needle, int m, int *lps) {
    int len = 0; // length of the previous longest prefix suffix
    int i = 1;

    lps[0] = 0; // lps[0] is always 0

    while (i < m) {
        if (needle[i] == needle[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int strStr(char *haystack, char *needle) {
    int m = strlen(needle);
    int n = strlen(haystack);
    int lps[m];
    int i = 0; // index for haystack
    int j = 0; // index for needle

    if (m == 0) return 0;

    computeLPSArray(needle, m, lps);

    while (i < n) {
        if (needle[j] == haystack[i]) {
            i++;
            j++;
        }

        if (j == m) {
            return i - j;
        } else if (i < n && needle[j] != haystack[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    return -1;
}