class Solution {
public:
    // int n;
    // vector<vector<int>> dp;
    // int solve(int i, int value, vector<vector<int>>& costs) {
    //     // base case
    //     if (i == n)
    //         return 0;
    //     if (dp[i][value] != -1)
    //         return dp[i][value];

    //     int take = INT_MAX;
    //     for (int idx = 0; idx < 3; idx++) {
    //         if (idx != value) {
    //             int val = costs[i][value] + solve(i + 1, idx, costs);
    //             take = min(take, val);
    //         }
    //     }
    //     return dp[i][value] = take;
    // }
    // int minCost(vector<vector<int>>& costs) {
    //     n = costs.size();
    //     dp.assign(n + 1, vector<int>(3, -1));
    //     int ans = INT_MAX;
    //     for (int i = 0; i < 3; i++) {
    //         ans = min(ans, solve(0, i, costs));
    //     }
    //     return ans;
    // }
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        vector<vector<int>>dp(n,vector<int>(3,0));
        //base case
        dp[n-1][0] = costs[n-1][0];
        dp[n-1][1] = costs[n-1][1];
        dp[n-1][2] = costs[n-1][2];

        for(int i = n-2;i>=0;i--){
            dp[i][0] = costs[i][0] + min(dp[i+1][1],dp[i+1][2]);
            dp[i][1] = costs[i][1] + min(dp[i+1][0],dp[i+1][2]);
            dp[i][2] = costs[i][2] + min(dp[i+1][1],dp[i+1][0]);
        }
        return min({dp[0][0], dp[0][1], dp[0][2]});
    }
};