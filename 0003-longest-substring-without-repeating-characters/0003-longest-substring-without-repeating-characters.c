int lengthOfLongestSubstring(char* s) {
    int last[256];
    
    for (int i = 0; i < 256; i++) {
        last[i] = -1;
    }

    int left = 0;
    int maxLength = 0;

    for (int right = 0; s[right] != '\0'; right++) {

        unsigned char ch = s[right];

        if (last[ch] >= left) {
            left = last[ch] + 1;
        }

        last[ch] = right;

        int length = right - left + 1;

        if (length > maxLength) {
            maxLength = length;
        }
    }

    return maxLength;
}