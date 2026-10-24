# Distinct Subsequences

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

Given two strings s and t, return  *the number of distinct*   ***subsequences** ** of  *s*  which equals *t.

The test cases are generated so that the answer fits on a 32-bit signed integer.

 

 **Example 1:** 

```
Input: s = "rabbbit", t = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from s.
rabbbit
rabbbit
rabbbit

```

 **Example 2:** 

```
Input: s = "babgbag", t = "bag"
Output: 5
Explanation:
As shown below, there are 5 ways you can generate "bag" from s.
babgbag
babgbag
babgbag
babgbag
babgbag
```

 

 **Constraints:** 

- 1 <= s.length, t.length <= 1000
- s and t consist of English letters.

## Solution

**Language:** C++  
**Runtime:** 43 ms (beats 9.74%)  
**Memory:** 44 MB (beats 38.37%)  
**Submitted:** 2026-10-24T12:41:41.168Z  

```cpp
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<vector<double>> dp(n + 1, vector<double>(m + 1, 0));

        // Base cases
        for (int i = 0; i <= n; i++) {
            dp[i][m] = 1;
        }

        for (int j = 0; j < m; j++) {
            dp[n][j] = 0;
        }

        // Bottom-up DP
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (s[i] == t[j]) {
                    dp[i][j] = dp[i + 1][j + 1] + dp[i + 1][j];
                } else {
                    dp[i][j] = dp[i + 1][j];
                }
            }
        }

        return (int)dp[0][0];
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/distinct-subsequences/)