# Integer Break

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an integer `n`, break it into the sum of `k`  **positive integers**, where `k >= 2`, and maximize the product of those integers.

Return  *the maximum product you can get*.

 

 **Example 1:** 

```
Input: n = 2
Output: 1
Explanation: 2 = 1 + 1, 1 × 1 = 1.

```

 **Example 2:** 

```
Input: n = 10
Output: 36
Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.

```

 

 **Constraints:** 

- 2 <= n <= 58

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 8.2 MB (beats 56.91%)  
**Submitted:** 2026-10-26T18:30:25.719Z  

```cpp


class Solution {
public:
    int integerBreak(int n) {

        if (n == 2) return 1;
        if (n == 3) return 2;

        if (n % 3 == 0)
            return pow(3, n / 3);

        if (n % 3 == 1)
            return pow(3, n / 3 - 1) * 4;

        return pow(3, n / 3) * 2;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/integer-break/)