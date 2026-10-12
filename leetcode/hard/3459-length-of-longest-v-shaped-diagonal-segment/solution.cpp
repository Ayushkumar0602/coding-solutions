class Solution {
public:
    int m, n;
    int dr[4] = {-1, 1, 1, -1};
    int dc[4] = {1, 1, -1, -1};

    int solve(vector<vector<int>>& grid, int r, int c,
              int dir, bool turned, int need) {

        int ans = 0;
        int nr = r + dr[dir];
        int nc = c + dc[dir];

        
        if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
            grid[nr][nc] == need) {

            int nextNeed;
            if (need == 2)
                nextNeed = 0;
            else
                nextNeed = 2;

            ans = 1 + solve(grid, nr, nc, dir, turned, nextNeed);
        }

        // Turn clockwise once
        if (turned == false) {
            int nd = (dir + 1) % 4;

            nr = r + dr[nd];
            nc = c + dc[nd];

            if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                grid[nr][nc] == need) {

                int nextNeed;
                if (need == 2)
                    nextNeed = 0;
                else
                    nextNeed = 2;

                int len = 1 + solve(grid, nr, nc, nd, true, nextNeed);

                ans = max(ans, len);
            }
        }

        return ans;
    }

    int lenOfVDiagonal(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    for (int d = 0; d < 4; d++) {
                        int len = 1 + solve(grid, i, j, d, false, 2);
                        ans = max(ans, len);
                    }
                }
            }
        }

        return ans;
    }
};