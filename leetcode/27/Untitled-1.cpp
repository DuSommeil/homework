#include <stdio.h>

int removeElement(int* nums, int numsSize, int val) {
    int k = 0; // Counter for elements not equal to val
    
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != val) {
            nums[k] = nums[i]; // Place the non-val element at the next available position
            k++;
        }
    }
    
    return k;
}

int main() {
    int nums[] = {2, 1, 5, 6, 5, 5, 2, 7}; // Declare nums as an array
    int numsSize = sizeof(nums) / sizeof(nums[0]); // Calculate the array size
    int val = 5;
    
    int k = removeElement(nums, numsSize, val);
    
    // Output the result
    printf("Modified array: ");
    for (int i = 0; i < k; i++) {
        printf("%d ", nums[i]);
    }
    printf("\nNumber of elements not equal to %d: %d\n", val, k);
    
    return 0;
}
