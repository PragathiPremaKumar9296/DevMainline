#include <stdio.h>
#include <stdlib.h>

int max_area (int *height, int heightSize) {
    int max_water = 0, current_area = 0;
    int left = 0, right = heightSize - 1;

    while (left < right) {
        int width = right - left;
        int minHeight = (height[left] < height[right]) ? height[left] : height[right];
        current_area = width * minHeight;

        if (current_area > max_water)
            max_water = current_area;
        
        if (height[left] < height[right])
            left++;
        else
            right--;
    }
    return max_water;
}

int main() {
    int heights1[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int size1 = sizeof(heights1) / sizeof(heights1[0]);
    printf("Output: %d\n", max_area(heights1, size1));  // Output: 49

    int heights2[] = {1, 1};
    int size2 = sizeof(heights2) / sizeof(heights2[0]);
    printf("Output: %d\n", max_area(heights2, size2));  // Output: 1

    return 0;
}