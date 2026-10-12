# Length of Longest V-Shaped Diagonal Segment

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given a 2D integer matrix `grid` of size `n x m`, where each element is either `0`, `1`, or `2`.

A  **V-shaped diagonal segment**  is defined as:

- The segment starts with 1.
- The subsequent elements follow this infinite sequence: 2, 0, 2, 0,....
- The segment: Starts along a diagonal direction (top-left to bottom-right, bottom-right to top-left, top-right to bottom-left, or bottom-left to top-right). Continues the sequence in the same diagonal direction. Makes at most one clockwise 90-degree turn to another diagonal direction while maintaining the sequence.

Return the  **length**  of the  **longest**   **V-shaped diagonal segment**. If no valid segment  *exists*, return 0.

 

 **Example 1:** 

 **Input:**  grid = [[2,2,1,2,2],[2,0,2,2,0],[2,0,1,1,0],[1,0,2,2,2],[2,0,0,2,2]]

 **Output:**  5

 **Explanation:** 

The longest V-shaped diagonal segment has a length of 5 and follows these coordinates: `(0,2) → (1,3) → (2,4)`, takes a  **90-degree clockwise turn**  at `(2,4)`, and continues as `(3,3) → (4,2)`.

 **Example 2:** 

 **Input:**  grid = [[2,2,2,2,2],[2,0,2,2,0],[2,0,1,1,0],[1,0,2,2,2],[2,0,0,2,2]]

 **Output:**  4

 **Explanation:** 

The longest V-shaped diagonal segment has a length of 4 and follows these coordinates: `(2,3) → (3,2)`, takes a  **90-degree clockwise turn**  at `(3,2)`, and continues as `(2,1) → (1,0)`.

 **Example 3:** 

 **Input:**  grid = [[1,2,2,2,2],[2,2,2,2,0],[2,0,0,0,0],[0,0,2,2,2],[2,0,0,2,0]]

 **Output:**  5

 **Explanation:** 

The longest V-shaped diagonal segment has a length of 5 and follows these coordinates: `(0,0) → (1,1) → (2,2) → (3,3) → (4,4)`.

 **Example 4:** 

 **Input:**  grid = [[1]]

 **Output:**  1

 **Explanation:** 

The longest V-shaped diagonal segment has a length of 1 and follows these coordinates: `(0,0)`.

 

 **Constraints:** 

- n == grid.length
- m == grid[i].length
- 1 <= n, m <= 500
- grid[i][j] is either 0, 1 or 2.

## Solution

**Language:** C++  
**Runtime:** 1557 ms (beats 39.32%)  
**Memory:** 94.6 MB (beats 91.26%)  
**Submitted:** 2026-10-12T14:25:37.328Z  

```cpp
class Solution {
public:
    int m, n;
    int dr[4] = {-1, 1, 1, -1};
    int dc[4] = {1, 1, -1, -1};

    int solve(vector<vector<int>>& grid, int r, int c,
              int dir, bool turned, int need) {

        int ans = 0;
        int nr = r + dr[dir];
        int nc = c + dc[dir];

        
        if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
            grid[nr][nc] == need) {

            int nextNeed;
            if (need == 2)
                nextNeed = 0;
            else
                nextNeed = 2;

            ans = 1 + solve(grid, nr, nc, dir, turned, nextNeed);
        }

        // Turn clockwise once
        if (turned == false) {
            int nd = (dir + 1) % 4;

            nr = r + dr[nd];
            nc = c + dc[nd];

            if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                grid[nr][nc] == need) {

                int nextNeed;
                if (need == 2)
                    nextNeed = 0;
                else
                    nextNeed = 2;

                int len = 1 + solve(grid, nr, nc, nd, true, nextNeed);

                ans = max(ans, len);
            }
        }

        return ans;
    }

    int lenOfVDiagonal(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    for (int d = 0; d < 4; d++) {
                        int len = 1 + solve(grid, i, j, d, false, 2);
                        ans = max(ans, len);
                    }
                }
            }
        }

        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/length-of-longest-v-shaped-diagonal-segment/)