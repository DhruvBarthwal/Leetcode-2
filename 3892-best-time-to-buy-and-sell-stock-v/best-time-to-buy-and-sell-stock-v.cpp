class Solution {
public:
int n ;
vector<vector<vector<long long>>>dp;
long long solve(int i, int state,int k, vector<int>&prices){
    //base case
    if(i == n){
        if(state == 0) return 0;
        return LLONG_MIN/2;
    }
    if( k == 0){
        if(state == 0) return 0;
        return LLONG_MIN/2;
    }
    if(dp[i][state][k] != -1) return dp[i][state][k];

    long long ans = 0;
    if(state == 0){
        //buy
        long long take = -prices[i] + solve(i+1,1,k,prices);
        long long shortSell = prices[i] + solve(i+1,2,k,prices);
        long long skip = solve(i+1,0,k,prices);
        ans = max({take, skip,shortSell});
    }
    else if(state == 1){
        //sell
        long long take =  prices[i] + solve(i+1,0,k-1,prices);
        long long skip = solve(i+1,1,k,prices);
        ans = max(take,skip);
    }
    else{
        long long take = -prices[i] + solve(i+1,0,k-1,prices);
        long long skip = solve(i+1,2,k,prices);
        ans = max(take , skip);
    }
    return dp[i][state][k] = ans;
}
    long long maximumProfit(vector<int>& prices, int k) {
        n = prices.size();
        dp.assign(n+1,vector<vector<long long>>(3,vector<long long>(k+1,-1)));
        return solve(0,0,k,prices);
    }
};