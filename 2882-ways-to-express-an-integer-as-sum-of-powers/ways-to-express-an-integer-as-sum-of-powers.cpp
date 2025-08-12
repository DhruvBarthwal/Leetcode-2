class Solution {
public:
    static constexpr int MOD = 1e9+7;
    int solve(int curr, int target, int x, vector<vector<int>>&dp){
        //base case
        if(target == 0){
            return 1;
        }
        if(curr>target || pow(curr,x) > target){
            return 0;
        }
        if(dp[curr][target] != -1){
            return dp[curr][target];
        }
        int val = (int)pow(curr,x);
        //skip
        int skip = solve(curr+1,target,x,dp);
        //take
        int take = 0;
        if(val<= target){
             take = solve(curr+1,target-val,x,dp);
        }
        //return
        return dp[curr][target] = (take + skip)%MOD;
    }
    int numberOfWays(int n, int x) {
        //initialization
        int count = 0;
        vector<vector<int>>dp(n+1,(vector<int>(n+1,-1)));
        return solve(1,n,x,dp);

    }
};