# Jump Game

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given an integer array `nums`. You are initially positioned at the array's  **first index**, and each element in the array represents your maximum jump length at that position.

Return `true` *if you can reach the last index, or* `false` *otherwise*.

 

Original
C++
 **Example 1:** 

```
Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

```

 **Example 2:** 

```
Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.

```

 

 **Constraints:** 

- 1 <= nums.length <= 104
- 0 <= nums[i] <= 105

## Solution

**Language:** C++  
**Runtime:** 110 ms (beats 12.87%)  
**Memory:** 54.7 MB (beats 8.02%)  
**Submitted:** 2026-11-27T13:30:11.136Z  

```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n + 1, 0);

        dp[n - 1] = 1;
        dp[n] = 1;

        for (int index = n - 2; index >= 0; index--) {

            bool ans = false;

            for (int head = 1;
                 head <= nums[index] && index + head <= n;
                 head++) {

                ans = ans || dp[index + head];

                if (ans)
                    break;
            }

            dp[index] = ans;
        }

        return dp[0];
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/jump-game/)