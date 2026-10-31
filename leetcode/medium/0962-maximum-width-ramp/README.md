# Maximum Width Ramp

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

A  **ramp**  in an integer array `nums` is a pair `(i, j)` for which `i < j` and `nums[i] <= nums[j]`. The  **width**  of such a ramp is `j - i`.

Given an integer array `nums`, return  *the maximum width of a  **ramp**  in* `nums`. If there is no  **ramp**  in `nums`, return `0`.

 

 **Example 1:** 

```
Input: nums = [6,0,8,2,1,5]
Output: 4
Explanation: The maximum width ramp is achieved at (i, j) = (1, 5): nums[1] = 0 and nums[5] = 5.

```

 **Example 2:** 

```
Input: nums = [9,8,1,0,1,9,4,0,4,1]
Output: 7
Explanation: The maximum width ramp is achieved at (i, j) = (2, 9): nums[2] = 1 and nums[9] = 1.

```

 

 **Constraints:** 

- 2 <= nums.length <= 5 * 104
- 0 <= nums[i] <= 5 * 104

## Solution

**Language:** C++  
**Runtime:** 7 ms (beats 54.01%)  
**Memory:** 47.9 MB (beats 97.98%)  
**Submitted:** 2026-10-31T10:19:11.991Z  

```cpp
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        stack<int> s;
        
        // Step 1: Build a decreasing stack of indices
        for (int i = 0; i < n; ++i) {
            if (s.empty() || nums[s.top()] > nums[i]) {
                s.push(i);
            }
        }
        
        int maxWidth = 0;
        
        // Step 2: Traverse from the end and find maximum width ramp
        for (int j = n - 1; j >= 0; --j) {
            while (!s.empty() && nums[s.top()] <= nums[j]) {
                maxWidth = max(maxWidth, j - s.top());
                s.pop();
            }
        }
        
        return maxWidth;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/maximum-width-ramp/)