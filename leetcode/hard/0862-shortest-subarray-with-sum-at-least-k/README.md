# Shortest Subarray with Sum at Least K

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

Given an integer array `nums` and an integer `k`, return  *the length of the shortest non-empty  **subarray**  of* `nums` *with a sum of at least* `k`. If there is no such  **subarray**, return `-1`.

A  **subarray**  is a  **contiguous**  part of an array.

 

 **Example 1:** 

```
Input: nums = [1], k = 1
Output: 1

```

 **Example 2:** 

```
Input: nums = [1,2], k = 4
Output: -1

```

 **Example 3:** 

```
Input: nums = [2,-1,2], k = 3
Output: 3

```

 

 **Constraints:** 

- 1 <= nums.length <= 105
- -105 <= nums[i] <= 105
- 1 <= k <= 109

## Solution

**Language:** C++  
**Runtime:** 17 ms (beats 49.50%)  
**Memory:** 68.8 MB (beats 57.89%)  
**Submitted:** 2026-10-16T11:29:56.857Z  

```cpp
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        //     //    2,-1,2
        //     //    2,1,3

        //     //    -5 2 2 3 4 -8
        //     //    -5,-3,-1, 2, 6,-2.   -2-(-1)=-1

        //     //    -5 2 2 3 4 -8

        //     vector<int> PrefixSum(nums.size(), 0);
        //     int a = 0;
        //     for (int i = 0; i < nums.size(); i++) {
        //         PrefixSum[i] = a + nums[i];
        //         a = PrefixSum[i];
        //     }

        //     int st = 0;
        //     int end = 0;
        //     int n = nums.size();
        //     int min_size = 0;

        //     while (end < n) {
        //         int subarray_sum = 0;
        //         if (st > 0) {
        //             subarray_sum = PrefixSum[end] - PrefixSum[st - 1];
        //         } else {
        //             subarray_sum = PrefixSum[end];
        //         }

        //         min_size = min(min_size, st - end +1);

        //         if (subarray_sum < k) {
        //             end++;
        //         } else {
        //             st++;
        //         }
        //     }
        //     return min_size;
        // }

        int n = nums.size();

        vector<long long> prefixSum(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }

        deque<int> dq;
        int min_size = n + 1;

        for (int end = 0; end <= n; end++) {

            // Find valid subarrays
            while (!dq.empty() && prefixSum[end] - prefixSum[dq.front()] >= k) {
                min_size = min(min_size, end - dq.front());
                dq.pop_front();
            }

            // Maintain increasing prefix sums
            while (!dq.empty() && prefixSum[end] <= prefixSum[dq.back()]) {
                dq.pop_back();
            }

            dq.push_back(end);
        }

        return min_size == n + 1 ? -1 : min_size;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/)