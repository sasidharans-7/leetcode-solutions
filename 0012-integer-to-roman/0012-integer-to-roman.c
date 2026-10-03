char* intToRoman(int num) {
    char* result = (char*)malloc(16 * sizeof(char));
    if (result == NULL) {
        return NULL; // Handle memory allocation failure
    }
    result[0] = '\0'; // Initialize result string to empty
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char* symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int i = 0;
    while (num > 0) {
        while (num >= values[i]) {
            strcat(result, symbols[i]);
            num -= values[i];
        }
        i++;
    }
    return result;
}