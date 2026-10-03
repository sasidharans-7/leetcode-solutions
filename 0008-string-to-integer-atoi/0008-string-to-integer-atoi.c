int myAtoi(char * s) {
    int sign = 1, base = 0, i = 0;
    while (s[i] == ' ') i++;
    if (s[i] == '-' || s[i] == '+') sign = (s[i++] == '-') ? -1 : 1;
    while (s[i] >= '0' && s[i] <= '9') {
        if (base > INT_MAX / 10 || (base == INT_MAX / 10 && s[i] - '0' > 7)) return (sign == 1) ? INT_MAX : INT_MIN;
        base = 10 * base + (s[i++] - '0');
    }
    return sign * base;
}