class Solution {
public:
int n;

int solve(int  i, int m,vector<int>&nums,vector<int>&dp){
    //base case
    if(i > m)  return 0;
    if(dp[i] != -1) return dp[i];

    int take = nums[i] + solve(i+2,m,nums,dp);
    int skip = solve(i+1,m,nums,dp);
    
    return dp[i] = max(take,skip);
}
    int rob(vector<int>& nums) {
        //initialization
        n = nums.size();
        if(n == 1) return nums[0];
        vector<int> dp1;
        vector<int> dp2;
        dp1.assign(n,-1);
        dp2.assign(n,-1);
        int ans = 0;

        ans = max(ans,solve(0,n-2,nums,dp1));
        ans = max(ans,solve(1,n-1,nums,dp2));

        return ans;
    }
};