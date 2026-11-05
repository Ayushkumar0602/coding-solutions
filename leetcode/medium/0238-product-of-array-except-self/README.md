# Product of Array Except Self

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an integer array `nums`, return  *an array*  `answer`  *such that*  `answer[i]`  *is equal to the product of all the elements of*  `nums`  *except*  `nums[i]`.

The product of any prefix or suffix of `nums` is  **guaranteed**  to fit in a  **32-bit**  integer.

You must write an algorithm that runs in `O(n)` time and without using the division operation.

 

 **Example 1:** 

```
Input: nums = [1,2,3,4]
Output: [24,12,8,6]

```

 **Example 2:** 

```
Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]

```

 

 **Constraints:** 

- 2 <= nums.length <= 105
- -30 <= nums[i] <= 30
- The input is generated such that answer[i] is guaranteed to fit in a 32-bit integer.

 

 **Follow up:**  Can you solve the problem in `O(1)` extra space complexity? (The output array  **does not**  count as extra space for space complexity analysis.)

## Solution

**Language:** C++  
**Runtime:** 3 ms (beats 35.57%)  
**Memory:** 42 MB (beats 29.37%)  
**Submitted:** 2026-11-05T13:11:00.370Z  

```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //withdivision approch


        // vector<int>ans(nums.size(),1);
        // int n=nums.size();
        // int product=1;
        // for(int i=0;i<n;i++){
        //     product=product*nums[i];
        // }

        // for(int i=0;i<n;i++){
        //     ans[i]=product/nums[i];  //error because we have to make it without using division
        // }

        // return ans;

        


        //without caring about space complexicity 

        vector<int>ans(nums.size(),1);
        vector<int>prefix(nums.size(),1);
        vector<int>suffix(nums.size(),1);
        int n=nums.size();
        
        //loop for finding the array of prefix 
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]*nums[i-1];
        }


         //loop for finding the array of srefix 
        for(int i=n-2;i>=0;i--){
            suffix[i]=suffix[i+1]*nums[i+1];
        }

        //multiplying  both prefix and suffix

        
        for(int i=0;i<n;i++){
            ans[i]=prefix[i]*suffix[i];
        }

        return ans;








    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/product-of-array-except-self/)