class Solution {
public:
vector<vector<vector<int>>> dp;
int n;
const int M = 1e9 + 7;
int solve(int i, int g1, int g2, vector<int>&nums){
    if(i == n) return (g1 != 0 && g1 == g2);
    if(dp[i][g1][g2] != -1) return dp[i][g1][g2];

    int ans = solve(i+1,g1,g2,nums);

    int ng1 = (g1 == 0) ? nums[i] : gcd(g1,nums[i]);
    ans = (ans + solve(i+1,ng1,g2,nums)) % M;

    int ng2 = (g2 == 0) ? nums[i] : gcd(g2,nums[i]); 
    ans = (ans + solve(i+1,g1,ng2,nums)) % M;

    return dp[i][g1][g2] = ans;
}
    int subsequencePairCount(vector<int>& nums) {
        n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        dp.assign(n,vector<vector<int>>(mx+1,vector<int>(mx+1,-1)));
        return solve(0,0,0,nums) % M;
    }
};