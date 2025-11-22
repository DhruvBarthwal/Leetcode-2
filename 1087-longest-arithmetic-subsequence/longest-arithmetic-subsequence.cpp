class Solution {
public:
int n;
vector<unordered_map<int,int>>dp;
int solve(int i, int diff, vector<int>&nums){
    //base case
    if(i < 0) return 0;
    if(dp[i].count(diff)) return dp[i][diff];

    int ans = 0;
    for(int k = i-1;k>=0;k--){
        if(nums[i] - nums[k] == diff){
            ans = max(ans,1+ solve(k,diff,nums));
        }
    }
    return dp[i][diff] = ans;
}
    int longestArithSeqLength(vector<int>& nums) {
        n = nums.size();
        dp.assign(n, unordered_map<int,int>());
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                int diff = nums[j] - nums[i];
                ans = max(ans,2 + solve(i,diff,nums));
            }
        }
        return ans;
    }
};