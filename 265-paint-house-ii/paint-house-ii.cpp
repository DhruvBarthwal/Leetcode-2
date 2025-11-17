class Solution {
public:
    int n;
    int k;
    vector<vector<int>> dp;
    int solve(int i, int value, vector<vector<int>>& costs) {
        // base case
        if (i == n)
            return 0;
        if (dp[i][value] != -1)
            return dp[i][value];

        int take = INT_MAX;
        for (int idx = 0; idx < k; idx++) {
            if (idx != value) {
                int val = costs[i][value] + solve(i + 1, idx, costs);
                take = min(take, val);
            }
        }
        return dp[i][value] = take;
    }
    int minCostII(vector<vector<int>>& costs) {
        n = costs.size();
        k = costs[0].size();
        dp.assign(n + 1, vector<int>(k, -1));
        int ans = INT_MAX;
        for (int i = 0; i < k; i++) {
            ans = min(ans, solve(0, i, costs));
        }
        return ans;
    }
};