class Solution {
public:
int solve(int target, vector<int>&nums, vector<int> & dp){
    //base case
    if(target == 0) return 1;
    if(target < 0) return 0;
    if(dp[target] != -1) return dp[target];

    int ans = 0;
    for(int num : nums){
        ans += solve(target - num,nums,dp);
    }
    return dp[target] = ans;
}
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>dp (target+1,-1);
        return solve(target,nums,dp);
    }
};