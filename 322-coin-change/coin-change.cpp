class Solution {
public:
    int n;
    vector<int> dp;

    int solve(int amount, vector<int>&coins){
        if(amount == 0) return 0;
        if(amount < 0) return INT_MAX;
        if(dp[amount] != -1) return dp[amount];

        int ans = INT_MAX;
        for(int i = 0;i<n;i++){
            int temp = solve(amount-coins[i],coins);
            if(temp != INT_MAX) {
                int mini = 1 + temp;
                ans = min(ans,mini);
            }
        }
        return dp[amount] = ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        //initialization
        n = coins.size();
        dp.assign(amount+1,-1);

        int ans = solve(amount,coins);

        return ans == INT_MAX ? -1 : ans;
    }
};