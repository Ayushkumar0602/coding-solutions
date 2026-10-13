# Word Search

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an `m x n` grid of characters `board` and a string `word`, return `true`  *if*  `word`  *exists in the grid*.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

 

 **Example 1:** 

```
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true

```

 **Example 2:** 

```
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true

```

 **Example 3:** 

```
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false

```

 

 **Constraints:** 

- m == board.length
- n = board[i].length
- 1 <= m, n <= 6
- 1 <= word.length <= 15
- board and word consists of only lowercase and uppercase English letters.

 

 **Follow up:**  Could you use search pruning to make your solution faster with a larger `board`?

## Solution

**Language:** C++  
**Runtime:** 194 ms (beats 72.18%)  
**Memory:** 10.4 MB (beats 80.99%)  
**Submitted:** 2026-10-13T19:04:06.333Z  

```cpp
class Solution {
public:
    bool solve(vector<vector<char>>& board, string& word, int i, int j, int st) {

        
        if (st == word.size())
            return true;

        
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size())
            return false;

        
        if (board[i][j] != word[st])
            return false;

       
        char temp = board[i][j];
        board[i][j] = '#';

        bool ans = solve(board, word, i + 1, j, st + 1) ||
                   solve(board, word, i - 1, j, st + 1) ||
                   solve(board, word, i, j + 1, st + 1) ||
                   solve(board, word, i, j - 1, st + 1);

        
        board[i][j] = temp;

        return ans;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (solve(board, word, i, j, 0))
                    return true;
            }
        }

        return false;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/word-search/)