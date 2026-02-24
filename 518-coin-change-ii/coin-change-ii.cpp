class Solution {
public:
vector<vector<int>>dp;
int n;
    int knapsack(int i,int amount, vector<int>& coins){
        //base case
        if(amount == 0) return 1;
        if(i == n || amount < 0) return 0;
        if(dp[i][amount] != -1) return dp[i][amount];

        int skip = knapsack(i+1,amount,coins);
        int take = (coins[i] <= amount) ? knapsack(i,amount-coins[i],coins) : 0;
        return dp[i][amount] = take + skip;
    }
    int change(int amount, vector<int>& coins) {    
        n = coins.size();
        dp.assign(n,vector<int>(amount+1,-1));
        return knapsack(0,amount,coins);
    }
};