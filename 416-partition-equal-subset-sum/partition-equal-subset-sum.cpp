class Solution {
public:
// vector<vector<int>> dp;
// int n;
//     int solve(int i,int sum, vector<int>&nums){
//         //base case
//         if(sum == 0) return true;
//         if(i == n || sum < 0) return false;

//         if(dp[i][sum] != -1) return dp[i][sum];

//         bool take = solve(i+1,sum - nums[i], nums);
//         bool skip = solve(i+1,sum,nums);

//         return dp[i][sum] = take || skip;
//     }
    // bool canPartition(vector<int>& nums) {
    //     n = nums.size();
    //     int sum = accumulate(nums.begin(),nums.end(),0);
    //     if(sum % 2 != 0) return false;
    //     int target = sum /2;
    //     dp.assign(n,vector<int>(target+1,-1));
    //     return solve(0,target,nums);
    // }

    // bool canPartition(vector<int>& nums) {
    //     int n = nums.size();
    //     int sum = accumulate(nums.begin(),nums.end(),0);
    //     if(sum % 2 != 0) return false;
    //     int target = sum /2;
    //     vector<vector<int>>dp(n,vector<int>(target+1,0));
        
    //     for(int i =0;i<n;i++) dp[i][0] = true;

    //     if(nums[0] <= target) dp[0][nums[0]] = true;

    //     for(int i=1;i<n;i++){
    //         for(int j = 1;j<=target;j++){
    //             dp[i][j] = dp[i-1][j] || (j >= nums[i] ? dp[i-1][j - nums[i]] : false);
    //         }
    //     }
    //     return dp[n-1][target];

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum % 2 != 0) return false;
        int target = sum /2;
        vector<int>dp(target+1,0);
        dp[0] = true;
        for(int num : nums){
            for(int j = target; j>=num;j--){
                dp[j] = dp[j] || dp[j - num];
            }
        }

        return dp[target];
    }
};