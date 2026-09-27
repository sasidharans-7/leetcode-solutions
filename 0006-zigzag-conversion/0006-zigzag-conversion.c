char* convert(char* s, int numRows) {
    int len = 0;

    while (s[len] != '\0') {
        len++;
    }

    // If only one row, no zigzag is needed
    if (numRows == 1 || numRows >= len) {
        return s;
    }

    char* result = malloc((len + 1) * sizeof(char));
    int index = 0;

    int cycle = 2 * numRows - 2;

    for (int row = 0; row < numRows; row++) {

        for (int i = row; i < len; i += cycle) {

            result[index++] = s[i];

            // Middle rows have an additional character
            if (row != 0 && row != numRows - 1) {

                int diagonal = i + cycle - 2 * row;

                if (diagonal < len) {
                    result[index++] = s[diagonal];
                }
            }
        }
    }

    result[index] = '\0';

    return result;
}