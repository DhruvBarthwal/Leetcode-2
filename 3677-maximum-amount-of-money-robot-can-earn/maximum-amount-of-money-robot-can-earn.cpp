class Solution {
public:
int n, m;
vector<vector<vector<int>>> dp;
    int solve(int i, int j, int k,vector<vector<int>>&coins){
        //base case
        if(i == n-1 && j == m-1){
            if(k != 0 && coins[i][j] < 0) return 0;
            else return coins[i][j];
        }
        if(dp[i][j][k] != INT_MIN) return dp[i][j][k];

        int ans = INT_MIN;

        if(i < n-1){
            int down = solve(i+1,j,k,coins);
            if(coins[i][j] < 0 && k > 0) ans = max(ans,solve(i+1,j,k-1,coins));
            if(down != INT_MIN) ans = max(ans,coins[i][j] + down);
        }
        if(j < m-1){
           int right = solve(i,j+1,k,coins);
           if(coins[i][j] < 0 && k > 0) ans = max(ans,solve(i,j+1,k-1,coins));
           if(right != INT_MIN) ans = max(ans,coins[i][j] + right);
        }
        return dp[i][j][k] = ans;
    }
    int maximumAmount(vector<vector<int>>& coins) {
        n = coins.size(), m = coins[0].size();
        dp.assign(n,vector<vector<int>>(m,vector<int>(3,INT_MIN)));
        return solve(0,0,2,coins);
    }
};