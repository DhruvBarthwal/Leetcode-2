class Solution {
public:
int solve(int i, int n ,int prev ,vector<int>&target, vector<int>&dp){
    //base case
    if(i == n) return 0;
    if(dp[i] != -1) return dp[i];

    int val = target[i] - prev;
    prev = target[i];
    if(val > 0){
        dp[i] = val + solve(i+1,n,prev,target,dp);
    }
    else{
        dp[i] = solve(i+1,n,prev,target,dp);
    }
    return dp[i];
    
}
    int minNumberOperations(vector<int>& target) {
        int n = target.size();
        vector<int>dp(n+1,-1);
        return solve(0,n,0,target,dp);
    }
};