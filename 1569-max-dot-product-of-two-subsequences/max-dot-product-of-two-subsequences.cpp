class Solution {
public:
vector<vector<long long>> dp;
int n,m;
long long solve(int i, int j, vector<int>&nums1 , vector<int>& nums2){
    if(i == n || j == m) return LLONG_MIN;
    if(dp[i][j] != -1) return dp[i][j];

    long long take = (nums1[i] * nums2[j]) + max(0LL, solve(i+1,j+1, nums1,nums2));
    long long skipI = solve(i+1,j, nums1, nums2);
    long long skipJ = solve(i,j+1, nums1, nums2);

    return dp[i][j] = max({take,skipI,skipJ});
}
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size();
        m = nums2.size();
        dp.assign(n+1,vector<long long>(m+1,-1));
        return solve(0,0,nums1,nums2);
    }
};