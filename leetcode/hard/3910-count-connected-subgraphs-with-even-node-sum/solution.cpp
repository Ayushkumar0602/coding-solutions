class Solution {
public:
    vector<vector<int>> subsets;
    vector<int> subset;

    void generate(int i, int n) {

        if (i == n) {
            subsets.push_back(subset);
            return;
        }

        // Include
        subset.push_back(i);
        generate(i + 1, n);

        // Exclude
        subset.pop_back();
        generate(i + 1, n);
    }

    bool check(vector<vector<int>>& adj,
               vector<int>& nums,
               unordered_map<int, bool>& mp,
               int st,
               int total) {

        queue<int> q;
        unordered_map<int, bool> visited;

        q.push(st);
        visited[st] = true;

        int sum = 0;
        int count = 0;

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            sum += nums[node];
            count++;

            for (int next : adj[node]) {

                if (mp[next] && !visited[next]) {

                    visited[next] = true;
                    q.push(next);
                }
            }
        }

        // All selected nodes must be connected
        // Their total sum must be even

        return (count == total && sum % 2 == 0);
    }

    int evenSumSubgraphs(vector<int>& nums,
                         vector<vector<int>>& edges) {

        int n = nums.size();
        int ans = 0;

        vector<vector<int>> adj(n);

        for (int i = 0; i < edges.size(); i++) {

            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Generate all subsets
        generate(0, n);

        // Check every subset
        for (int i = 0; i < subsets.size(); i++) {

            if (subsets[i].empty()) {
                continue;
            }

            unordered_map<int, bool> mp;

            for (int j = 0; j < subsets[i].size(); j++) {
                mp[subsets[i][j]] = true;
            }

            int start = subsets[i][0];

            if (check(adj, nums, mp, start, subsets[i].size())) {
                ans++;
            }
        }

        return ans;
    }
};