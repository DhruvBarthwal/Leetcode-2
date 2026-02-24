class Solution {
public:
int n;
vector<int> dp;
    int knapsack(int amount, vector<int>&coins){
        //base case 
        if(amount == 0) return 0;
        if(amount < 0) return INT_MAX;
        if(dp[amount] != -1) return dp[amount];

        int ans = INT_MAX;
        for(int j = n-1;j>=0;j--){
            int mini = knapsack(amount - coins[j], coins);
            if(mini != INT_MAX) ans = min(ans,mini + 1); 
        }
        return dp[amount] = ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        n = coins.size();
        dp.assign(amount+1,-1);
        int ans = knapsack(amount,coins);
        return ans == INT_MAX ? -1 : ans;
    }
};