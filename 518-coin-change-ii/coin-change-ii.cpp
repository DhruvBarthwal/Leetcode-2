class Solution {
public:
    int memo(int i, int amount, int n,vector<int> &coins, vector<vector<int>>&dp){
        //base case
        if(amount == 0){
            return 1;
        }
        if(i == 0){
            return amount % coins[0] == 0;
        }
        if(dp[i][amount] != -1){
            return dp[i][amount];
        }
        int take = 0;
        if(coins[i]<=amount){
            take = memo(i,amount-coins[i],n,coins,dp);
        }
        int skip = memo(i-1, amount,n,coins,dp);
        return dp[i][amount] = take + skip; 
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1, -1));
        return memo(n-1,amount,n,coins,dp);   
    }
};