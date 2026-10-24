class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<vector<double>> dp(n + 1, vector<double>(m + 1, 0));

        // Base cases
        for (int i = 0; i <= n; i++) {
            dp[i][m] = 1;
        }

        for (int j = 0; j < m; j++) {
            dp[n][j] = 0;
        }

        // Bottom-up DP
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (s[i] == t[j]) {
                    dp[i][j] = dp[i + 1][j + 1] + dp[i + 1][j];
                } else {
                    dp[i][j] = dp[i + 1][j];
                }
            }
        }

        return (int)dp[0][0];
    }
};