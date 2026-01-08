class Solution {
public:
// CASE 1 : Top Down Approach
// vector<vector<long long>> dp;
// int n,m;
// long long solve(int i, int j, vector<int>&nums1 , vector<int>& nums2){
//     if(i == n || j == m) return LLONG_MIN;
//     if(dp[i][j] != -1) return dp[i][j];

//     long long take = (nums1[i] * nums2[j]) + max(0LL, solve(i+1,j+1, nums1,nums2));
//     long long skipI = solve(i+1,j, nums1, nums2);
//     long long skipJ = solve(i,j+1, nums1, nums2);

//     return dp[i][j] = max({take,skipI,skipJ});
// }
    // int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
    //     n = nums1.size();
    //     m = nums2.size();
    //     dp.assign(n+1,vector<long long>(m+1,-1));
    //     return solve(0,0,nums1,nums2);
    // }

//CASE 2 : BOTTOM UP APPROACH
    vector<vector<long long>> dp;
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        dp.assign(n+1,vector<long long>(m+1,LLONG_MIN));
        
        for(int i = n-1;i>=0;i--){
            for(int j = m-1;j>=0;j--){
                long long take = (nums1[i] * nums2[j]) + max(0LL, dp[i+1][j+1]);
                long long skip1 = dp[i+1][j];
                long long skip2 = dp[i][j+1];
                dp[i][j] = max({take,skip1,skip2});
            }
        }
        return dp[0][0];
    }
};