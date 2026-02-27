class Solution {
public:
vector<vector<int>> dp;
int n;
    int solve(int i, int flag, vector<int>&prices){
        //base case
        if(i == n) return 0;
        if(dp[i][flag] != -1) return dp[i][flag];

        int ans =solve(i+1,flag,prices);
        if(!flag){
            ans = max(ans ,-prices[i] +  solve(i+1,1,prices));
        }
        else{
            ans = max(ans, prices[i] + solve(i+1,0,prices));
        }
        return dp[i][flag] = ans;
    }
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        dp.assign(n+1,vector<int>(2,-1));
        return solve(0,0,prices);
    }
};