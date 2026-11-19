# Longest Increasing Path in a Matrix

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

Given an `m x n` integers `matrix`, return  *the length of the longest increasing path in* `matrix`.

From each cell, you can either move in four directions: left, right, up, or down. You  **may not**  move  **diagonally**  or move  **outside the boundary**  (i.e., wrap-around is not allowed).

 

Original
C++
 **Example 1:** 

```
Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
Output: 4
Explanation: The longest increasing path is [1, 2, 6, 9].

```

 **Example 2:** 

```
Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]
Output: 4
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.

```

 **Example 3:** 

```
Input: matrix = [[1]]
Output: 1

```

 

 **Constraints:** 

- m == matrix.length
- n == matrix[i].length
- 1 <= m, n <= 200
- 0 <= matrix[i][j] <= 231 - 1

## Solution

**Language:** C++  
**Runtime:** 8 ms (beats 80.61%)  
**Memory:** 20.7 MB (beats 65.72%)  
**Submitted:** 2026-11-19T20:02:44.134Z  

```cpp
class Solution {
public:
    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};

    int solve(vector<vector<int>>& matrix, int row, int col,
              int m, int n, vector<vector<int>>& dp) {

        if (dp[row][col] != -1) {
            return dp[row][col];
        }

        int length = 1;

        for (int i = 0; i < 4; i++) {
            int new_row = row + dr[i];
            int new_col = col + dc[i];

            if (new_row >= 0 && new_row < m &&
                new_col >= 0 && new_col < n &&
                matrix[new_row][new_col] > matrix[row][col]) {

                length = max(length,
                             1 + solve(matrix, new_row, new_col,
                                       m, n, dp));
            }
        }

        return dp[row][col] = length;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, solve(matrix, i, j, m, n, dp));
            }
        }

        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/longest-increasing-path-in-a-matrix/)