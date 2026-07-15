class Solution {
public:
vector<vector<vector<int>>> dp;
int n;
int solve(int i, int k, bool flag, vector<int>&prices){
    if(i == n || k == 0) return 0;
    if(dp[i][k][flag] != -1) return dp[i][k][flag];

    int ans = solve(i+1,k,flag,prices);
    //sell time
    if(flag){
        ans = max(ans, prices[i] + solve(i+1,k-1,0,prices));
    }   
    //buy time
    else{
        ans = max(ans,-prices[i] + solve(i+1,k,1,prices));
    }
    return dp[i][k][flag] = ans;
}
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        dp.assign(n,vector<vector<int>>(3,vector<int>(2,-1)));
        return solve(0,2,0,prices);
    }
};