class Solution {
public:
    int trap(vector<int>& height) {
        // Check if the array is empty
        if (height.empty()) {
            return 0; // Return 0 for empty input
        }

        int n = height.size();
        int left = 0, right = n - 1;
        int left_max = 0, right_max = 0;
        int water_trapped = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] >= left_max) {
                    left_max = height[left]; // Update left max
                } else {
                    water_trapped += left_max - height[left]; // Accumulate trapped water
                }
                left++; // Move left pointer
            } else {
                if (height[right] >= right_max) {
                    right_max = height[right]; // Update right max
                } else {
                    water_trapped += right_max - height[right]; // Accumulate trapped water
                }
                right--; // Move right pointer
            }
        }

        return water_trapped; // Return the total water trapped
    }
};