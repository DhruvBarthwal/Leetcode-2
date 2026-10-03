class Solution {
public:
//global variable
int n , m;
vector<vector<int>> dp;
int solve(int i, int k, vector<int>&nums, vector<int>&multipliers){
    if(k >= m) return 0;
    if(dp[i][k] != -1) return dp[i][k];

    int take1 = (nums[i] * multipliers[k]) + solve(i+1,k+1,nums,multipliers);
    int j = n-1 - (k-i);
    int take2 = (nums[j] * multipliers[k]) + solve(i,k+1,nums,multipliers);

    return dp[i][k] = max(take1,take2);
}
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        n = nums.size(), m = multipliers.size();
        dp.assign(n,vector<int>(m+1,-1));
        return solve(0,0, nums, multipliers);
    }
};