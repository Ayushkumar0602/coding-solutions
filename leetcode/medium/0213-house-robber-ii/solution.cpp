class Solution {
public:
    int find(int index, vector<int>& nums, int n, vector<int>& dp) {
        if (index >= n) {
            return 0;
        }

        if (dp[index] != -1) {
            return dp[index];
        }

        return dp[index] = max(nums[index] + find(index + 2, nums, n, dp),
                           find(index + 1, nums, n, dp));
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
         if (n == 1) return nums[0];
        vector<int> dp(n + 1, -1);
        vector<int> dp2(n + 1, -1);

        return max(find(0, nums, n-1, dp),find(1,nums,n,dp2));
    }
};