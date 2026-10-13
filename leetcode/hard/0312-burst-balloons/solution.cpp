// // class Solution {
// // public:
// //     int solve(vector<int>& nums, vector<bool>& alive, int remaining) {
// //         if (remaining == 0) {
// //             return 0;
// //         }

// //         int cost = 0;

// //         for (int index = 0; index < nums.size(); index++) {
// //             if (!alive[index]) {
// //                 continue;
// //             }

// //             int left = 1;
// //             int right = 1;

// //             for (int i = index - 1; i >= 0; i--) {
// //                 if (alive[i]) {
// //                     left = nums[i];
// //                     break;
// //                 }
// //             }

// //             for (int i = index + 1; i < nums.size(); i++) {
// //                 if (alive[i]) {
// //                     right = nums[i];
// //                     break;
// //                 }
// //             }

// //             alive[index] = false;

// //             int current = left * nums[index] * right;
// //             cost = max(cost, current + solve(nums, alive, remaining - 1));

// //             alive[index] = true;
// //         }

// //         return cost;
// //     }

// //     int maxCoins(vector<int>& nums) {
// //         vector<bool> alive(nums.size(), true);
// //         return solve(nums, alive, nums.size());
// //     }
// // };




// class Solution {
// public:
//     vector<int> nums;
//     vector<int> dp;
//     int n;

//     int solve(int mask) {
//         if (mask == 0) {
//             return 0;
//         }

//         if (dp[mask] != -1) {
//             return dp[mask];
//         }

//         int cost = 0;

//         for (int index = 0; index < n; index++) {
//             if ((mask & (1 << index)) == 0) {
//                 continue;
//             }

//             int left = 1;
//             int right = 1;

//             for (int i = index - 1; i >= 0; i--) {
//                 if (mask & (1 << i)) {
//                     left = nums[i];
//                     break;
//                 }
//             }

//             for (int i = index + 1; i < n; i++) {
//                 if (mask & (1 << i)) {
//                     right = nums[i];
//                     break;
//                 }
//             }

//             int current = left * nums[index] * right;

//             int newMask = mask ^ (1 << index);

//             cost = max(cost, current + solve(newMask));
//         }

//         return dp[mask] = cost;
//     }

//     int maxCoins(vector<int>& arr) {
//         nums = arr;
//         n = nums.size();

//         dp.assign(1 << n, -1);

//         return solve((1 << n) - 1);
//     }
// };


class Solution {
public:
    int maxCoins(vector<int>& nums) {
        //including the nums[-1] and nums[n]
        int n = nums.size() + 2;        
        vector<vector<int>> dp(n, vector<int>(n));
        vector<int> new_nums(n, 1);
        int i = 1;
        for(auto num : nums) {
            new_nums[i++] = num;
        }
        for(int len = 2; len <= n; len++) { 
            //iterate from interval length from 2 to n
            for(int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                //select between left and right boundary (i, j)
                for(int k = i + 1; k < j; k++) { 
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + new_nums[i] * new_nums[k] * new_nums[j]);
                }
            }
        }
        return dp[0][n - 1];
    }
};
