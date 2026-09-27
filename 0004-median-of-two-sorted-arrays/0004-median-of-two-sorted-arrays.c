double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {

    // Make nums1 the smaller array
    if (nums1Size > nums2Size) {
        int* temp = nums1;
        nums1 = nums2;
        nums2 = temp;

        int tempSize = nums1Size;
        nums1Size = nums2Size;
        nums2Size = tempSize;
    }

    int m = nums1Size;
    int n = nums2Size;

    int left = 0;
    int right = m;

    while (left <= right) {

        // Partition nums1
        int partition1 = (left + right) / 2;

        // Partition nums2
        int partition2 = (m + n + 1) / 2 - partition1;

        int maxLeft1;
        int minRight1;
        int maxLeft2;
        int minRight2;

        if (partition1 == 0)
            maxLeft1 = -2147483648;
        else
            maxLeft1 = nums1[partition1 - 1];

        if (partition1 == m)
            minRight1 = 2147483647;
        else
            minRight1 = nums1[partition1];

        if (partition2 == 0)
            maxLeft2 = -2147483648;
        else
            maxLeft2 = nums2[partition2 - 1];

        if (partition2 == n)
            minRight2 = 2147483647;
        else
            minRight2 = nums2[partition2];

        // Correct partition
        if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {

            // Odd total length
            if ((m + n) % 2 == 1) {
                if (maxLeft1 > maxLeft2)
                    return maxLeft1;
                else
                    return maxLeft2;
            }

            // Even total length
            int leftMax;

            if (maxLeft1 > maxLeft2)
                leftMax = maxLeft1;
            else
                leftMax = maxLeft2;

            int rightMin;

            if (minRight1 < minRight2)
                rightMin = minRight1;
            else
                rightMin = minRight2;

            return (leftMax + rightMin) / 2.0;
        }

        // Move partition1 to the right
        if (maxLeft1 > minRight2)
            right = partition1 - 1;

        // Move partition1 to the left
        else
            left = partition1 + 1;
    }

    return 0.0;
}