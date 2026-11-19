class Solution {
public:
    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};

    int solve(vector<vector<int>>& matrix, int row, int col,
              int m, int n, vector<vector<int>>& dp) {

        if (dp[row][col] != -1) {
            return dp[row][col];
        }

        int length = 1;

        for (int i = 0; i < 4; i++) {
            int new_row = row + dr[i];
            int new_col = col + dc[i];

            if (new_row >= 0 && new_row < m &&
                new_col >= 0 && new_col < n &&
                matrix[new_row][new_col] > matrix[row][col]) {

                length = max(length,
                             1 + solve(matrix, new_row, new_col,
                                       m, n, dp));
            }
        }

        return dp[row][col] = length;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, solve(matrix, i, j, m, n, dp));
            }
        }

        return ans;
    }
};