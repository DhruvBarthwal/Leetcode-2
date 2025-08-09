class Solution {
private:
    int solve(vector<int>& nums, int n , int i,int prevIndex, vector<vector<int>>&dp){
        //base case
        if(i == n){
            return 0;
        }
        if(dp[i][prevIndex+1] != -1){
            return dp[i][prevIndex+1];
        }
        //include and exclude process
        int skip = solve(nums,n,i+1,prevIndex,dp);

        int take = 0;
        if(prevIndex == -1 || nums[prevIndex]<nums[i]){
             take = 1+ solve(nums,n,i+1,i,dp);
        }
        //return value
        return dp[i][prevIndex+1] = max(take,skip);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        //initialization
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(nums,n,0,-1,dp);
    }
};