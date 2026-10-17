# 132 Pattern

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an array of `n` integers `nums`, a  **132 pattern**  is a subsequence of three integers `nums[i]`, `nums[j]` and `nums[k]` such that `i < j < k` and `nums[i] < nums[k] < nums[j]`.

Return `true` *if there is a  **132 pattern**  in* `nums` *, otherwise, return* `false` *.* 

 

 **Example 1:** 

```
Input: nums = [1,2,3,4]
Output: false
Explanation: There is no 132 pattern in the sequence.

```

 **Example 2:** 

```
Input: nums = [3,1,4,2]
Output: true
Explanation: There is a 132 pattern in the sequence: [1, 4, 2].

```

 **Example 3:** 

```
Input: nums = [-1,3,2,0]
Output: true
Explanation: There are three 132 patterns in the sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].

```

 

 **Constraints:** 

- n == nums.length
- 1 <= n <= 2 * 105
- -109 <= nums[i] <= 109

## Solution

**Language:** C++  
**Runtime:** 13 ms (beats 38.18%)  
**Memory:** 70.7 MB (beats 51.47%)  
**Submitted:** 2026-10-17T06:28:12.484Z  

```cpp
// // class Solution {
// // public:
// //     bool solve(vector<int>& nums, int index, int prev_element, int count) {

// //         if (count == 3) {
// //             return true;
// //         }

// //         if (index >= nums.size()) {
// //             return false;
// //         }

// //         bool take = false;
// //         bool notake = false;

// //         if (prev_element == -1 || (count == 1 && nums[index] > prev_element)
// //         ||
// //             (count == 2 && nums[index] < prev_element)) {

// //             take = solve(nums, index + 1, nums[index], count + 1);
// //         }

// //         notake = solve(nums, index + 1, prev_element, count);

// //         return take || notake;
// //     }
// //     bool find132pattern(vector<int>& nums) { return solve(nums, 0, -1, 0); }
// // };

// class Solution {
// public:
//     bool find132pattern(vector<int>& nums) {
//         vector<int> nextGreater(nums.size(), -1);
//         vector<int> nextSmaller(nums.size(), -1);

//         stack<int> s;
//         int n = nums.size();

//         for (int i = 0; i < n; i++) {
//             while (!s.empty() && nums[s.top()] < nums[i]) {
//                 nextGreater[s.top()] = i;
//                 s.pop();
//             }

//             s.push(i);
//         }

//         for (int i = 0; i < n; i++) {
//             while (!s.empty() && nums[s.top()] > nums[i]) {
//                 nextSmaller[s.top()] = i;
//                 s.pop();
//             }

//             s.push(i);
//         }

//         for (int i = 0; i < n; i++) {
//             // next greater index of nums[i]
//             int next_index = nextGreater[i];
//             if (next_index != -1) {
//                 continue;
//             }

//             if (nextSmaller[next_index] != -1) {
//                 return true;
//             }
//         }

//         return false;

        
//     }
// };

// above two soln is not the right solution and will fail on submision , 

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> s;
        int second = INT_MIN;

        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] < second) {
                return true;
            }

            while (!s.empty() && nums[i] > s.top()) {
                second = s.top();
                s.pop();
            }

            s.push(nums[i]);
        }

        return false;
    }
};

```

---

[View on LeetCode](https://leetcode.com/problems/132-pattern/)