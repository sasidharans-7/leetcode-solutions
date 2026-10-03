int maxArea(int* height, int heightSize) {
    int left = 0;
    int right = heightSize - 1;
    int maxArea = 0;

    while (left < right) {
        int currentArea = (right - left) * (height[left] < height[right] ? height[left] : height[right]);
        if (currentArea > maxArea) {
            maxArea = currentArea;
        }
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return maxArea;
}