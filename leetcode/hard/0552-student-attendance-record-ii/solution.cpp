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