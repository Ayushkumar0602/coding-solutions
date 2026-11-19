# Student Attendance Record II

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

An attendance record for a student can be represented as a string where each character signifies whether the student was absent, late, or present on that day. The record only contains the following three characters:

- 'A': Absent.
- 'L': Late.
- 'P': Present.

Any student is eligible for an attendance award if they meet  **both**  of the following criteria:

- The student was absent ('A') for strictly fewer than 2 days total.
- The student was never late ('L') for 3 or more consecutive days.

Given an integer `n`, return  *the  **number**  of possible attendance records of length*  `n` *that make a student eligible for an attendance award. The answer may be very large, so return it  **modulo*** `109 + 7`.

 

Original
C++
 **Example 1:** 

```
Input: n = 2
Output: 8
Explanation: There are 8 records with length 2 that are eligible for an award:
"PP", "AP", "PA", "LP", "PL", "AL", "LA", "LL"
Only "AA" is not eligible because there are 2 absences (there need to be fewer than 2).

```

 **Example 2:** 

```
Input: n = 1
Output: 3

```

 **Example 3:** 

```
Input: n = 10101
Output: 183236316

```

 

 **Constraints:** 

- 1 <= n <= 105

## Solution

**Language:** C++  
**Runtime:** 146 ms (beats 60.81%)  
**Memory:** 18.1 MB (beats 63.72%)  
**Submitted:** 2026-11-19T20:03:13.764Z  

```cpp
class Solution {
public:
    const int MOD = 1000000007;

    int dp[100001][2][3];

    int solve(int n, int days, int c_a, int c_l) {

        // n days completed
        if (days == n) {
            return 1;
        }

        if (dp[days][c_a][c_l] != -1) {
            return dp[days][c_a][c_l];
        }

        long long a = 0;
        long long l = 0;
        long long p = 0;

        // A -> at most 1 absent
        if (c_a < 1) {
            a = solve(n, days + 1, c_a + 1, 0);
        }

        // L -> at most 2 consecutive late
        if (c_l < 2) {
            l = solve(n, days + 1, c_a, c_l + 1);
        }

        // P -> resets consecutive late count
        p = solve(n, days + 1, c_a, 0);

        return dp[days][c_a][c_l] = (a + l + p) % MOD;
    }

    int checkRecord(int n) {

        memset(dp, -1, sizeof(dp));

        return solve(n, 0, 0, 0);
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/student-attendance-record-ii/)