# Maximal Rectangle

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

Given a `rows x cols` binary `matrix` filled with `0`'s and `1`'s, find the largest rectangle containing only `1`'s and return  *its area*.

 

Original
C++
 **Example 1:** 

```
Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.

```

 **Example 2:** 

```
Input: matrix = [["0"]]
Output: 0

```

 **Example 3:** 

```
Input: matrix = [["1"]]
Output: 1

```

 

 **Constraints:** 

- rows == matrix.length
- cols == matrix[i].length
- 1 <= rows, cols <= 200
- matrix[i][j] is '0' or '1'.

## Solution

**Language:** C++  
**Runtime:** 13 ms (beats 27.55%)  
**Memory:** 22.1 MB (beats 19.57%)  
**Submitted:** 2026-11-19T20:02:26.722Z  

```cpp
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> leftSmallestIndex(n);
        vector<int> rightSmallestIndex(n);
        stack<int> s;

        for (int i = 0; i < n; i++) {
            while (!s.empty() && heights[s.top()] > heights[i]) {
                rightSmallestIndex[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }

        while (!s.empty()) {
            rightSmallestIndex[s.top()] = n;
            s.pop();
        }

        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && heights[s.top()] > heights[i]) {
                leftSmallestIndex[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }

        while (!s.empty()) {
            leftSmallestIndex[s.top()] = -1;
            s.pop();
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            ans = max(ans, abs(heights[i] * (rightSmallestIndex[i] -
                                             leftSmallestIndex[i] - 1)));
        }

        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row= matrix.size();
        int col = matrix[0].size();

        int ans =0;
        vector<int>height(col,0);

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]=='0'){
                    height[j]=0;
                }

                else{
                    height[j]+=1;
                }
            }

            ans=max(ans,largestRectangleArea(height));
        }

        return ans ;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/maximal-rectangle/)