# House Robber II

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are  **arranged in a circle.**  That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and  **it will automatically contact the police if two adjacent houses were broken into on the same night**.

Given an integer array `nums` representing the amount of money of each house, return  *the maximum amount of money you can rob tonight  **without alerting the police***.

 

 **Example 1:** 

```
Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.

```

 **Example 2:** 

```
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

```

 **Example 3:** 

```
Input: nums = [1,2,3]
Output: 3

```

 

 **Constraints:** 

- 1 <= nums.length <= 100
- 0 <= nums[i] <= 1000

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 10.6 MB (beats 58.44%)  
**Submitted:** 2026-10-24T12:41:53.919Z  

```cpp
class Solution {
public:
    int find(int index, vector<int>& nums, int n, vector<int>& dp) {
        if (index >= n) {
            return 0;
        }

        if (dp[index] != -1) {
            return dp[index];
        }

        return dp[index] = max(nums[index] + find(index + 2, nums, n, dp),
                           find(index + 1, nums, n, dp));
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
         if (n == 1) return nums[0];
        vector<int> dp(n + 1, -1);
        vector<int> dp2(n + 1, -1);

        return max(find(0, nums, n-1, dp),find(1,nums,n,dp2));
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/house-robber-ii/)