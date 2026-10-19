# Trapping Rain Water

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

Given `n` non-negative integers representing an elevation map where the width of each bar is `1`, compute how much water it can trap after raining.

 

 **Example 1:** 

```
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

```

 **Example 2:** 

```
Input: height = [4,2,0,3,2,5]
Output: 9

```

 

 **Constraints:** 

- n == height.length
- 1 <= n <= 2 * 104
- 0 <= height[i] <= 105

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 26 MB (beats 54.56%)  
**Submitted:** 2026-10-19T08:38:09.618Z  

```cpp
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
```

---

[View on LeetCode](https://leetcode.com/problems/trapping-rain-water/)