class Solution {
public:
//top down 
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
        int prev = 0, ans = 0;
        for(int i = 0;i<n;i++){
            int val = target[i] - prev;
            if(val > 0) ans += val;
            prev = target[i];
        }
        return ans;
    }
};