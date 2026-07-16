class Solution {
public:
vector<vector<int>> dp;
int n;
int solve(int i, int prev, vector<int>& nums){
    //base case
    if(i == n) return 0;
    if(dp[i][prev+1] != -1) return dp[i][prev+1];

    int ans = solve(i+1,prev,nums);

    if(prev == -1 || (prev != -1 && nums[prev] < nums[i])){
        ans = max(ans, 1 + solve(i+1,i,nums));
    }

    return dp[i][prev+1] = ans;
}
    int lengthOfLIS(vector<int>& nums) {
        //initialization
        n = nums.size();
        dp.assign(n,vector<int>(n+1,-1));

        return solve(0,-1,nums);  
    }
};