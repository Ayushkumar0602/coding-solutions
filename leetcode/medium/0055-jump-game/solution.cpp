class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n + 1, 0);

        dp[n - 1] = 1;
        dp[n] = 1;

        for (int index = n - 2; index >= 0; index--) {

            bool ans = false;

            for (int head = 1;
                 head <= nums[index] && index + head <= n;
                 head++) {

                ans = ans || dp[index + head];

                if (ans)
                    break;
            }

            dp[index] = ans;
        }

        return dp[0];
    }
};