class Solution {
public:
    int solve(int i, int j, vector<vector<int>> &dp, vector<int>& cuts){
        //base case
        if(i+1 == j) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int mini = INT_MAX;
        for(int k = i+1;k<j;k++){
            int ans = cuts[j] - cuts[i] + solve(i,k,dp,cuts) + solve(k,j,dp,cuts);
            mini = min(mini,ans);
        }
        return dp[i][j] = mini;
    }
    int minCost(int n, vector<int>& cuts) {
        //adding initial ans final points
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        int m = cuts.size();
        vector<vector<int>> dp(m, vector<int>(m, -1));
        return solve(0, m-1,dp, cuts);
    }
};