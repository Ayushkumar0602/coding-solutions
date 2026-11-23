# Unique Binary Search Trees

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an integer `n`, return  *the number of structurally unique  **BST'** s (binary search trees) which has exactly* `n` *nodes of unique values from*  `1`  *to*  `n`.

 

Original
C++
 **Example 1:** 

```
Input: n = 3
Output: 5

```

 **Example 2:** 

```
Input: n = 1
Output: 1

```

 

 **Constraints:** 

- 1 <= n <= 19

## Solution

**Language:** C++  
**Runtime:** 1 ms (beats 24.09%)  
**Memory:** 8.5 MB (beats 6.68%)  
**Submitted:** 2026-11-23T17:27:29.502Z  

```cpp
class Solution {
public:
    int numTrees(int n) {
        vector<long long> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;

        for (int nodes = 2; nodes <= n; nodes++) {
            for (int root = 1; root <= nodes; root++) {
                dp[nodes] += dp[root-1] * dp[nodes-root];
            }
        }

        return (int)dp[n];
    }
};

```

---

[View on LeetCode](https://leetcode.com/problems/unique-binary-search-trees/)