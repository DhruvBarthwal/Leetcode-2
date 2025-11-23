class Solution {
public:
// int n;
// vector<vector<int>> dp;
// int solve(int i ,int r, vector<int> &nums){
//     //base case
//     if(i == n){
//         return(r == 0 ? 0 : INT_MIN);
//     }
//     if(dp[i][r] != -1) return dp[i][r];

//     int take = nums[i] + solve(i+1,(r + nums[i])%3,nums);
//     int skip = solve(i+1,r,nums);

//     return dp[i][r] = max(take,skip);
// }   
//     int maxSumDivThree(vector<int>& nums) {
//         n = nums.size();
//         dp.assign(n+1,vector<int>(3,-1));
//         return solve(0,0,nums);
//     }
    // int maxSumDivThree(vector<int>& nums) {
    //     n = nums.size();
    //     dp.assign(n+1,vector<int>(3,INT_MIN));
    //     dp[n][0] = 0;
    //     for(int i = n-1;i>=0;i--){
    //         for(int r = 0;r<3;r++){
    //             int take = nums[i] + dp[i+1][(r+nums[i])%3];
    //             int skip = dp[i+1][r];
    //             dp[i][r] = max(take,skip); 
    //         }
    //     }
    //     return dp[0][0];
    // }
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<int>prev(3,INT_MIN), curr(3,INT_MIN);
        prev[0] = 0;
        for(int i = n-1;i>=0;i--){
            curr = prev;
            for(int r = 0;r<3;r++){
                int take = nums[i] + prev[(r+nums[i])%3];
                int skip = prev[r];
                curr[r] = max(take,skip); 
            }
            prev = curr;
        }
        return prev[0];
    }
};