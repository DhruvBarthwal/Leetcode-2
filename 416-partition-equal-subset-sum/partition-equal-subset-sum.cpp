class Solution {
public:
vector<vector<int>> dp;
int n;
    int solve(int i,int sum, vector<int>&nums){
        //base case
        if(sum == 0) return true;
        if(i == n || sum < 0) return false;

        if(dp[i][sum] != -1) return dp[i][sum];

        bool take = solve(i+1,sum - nums[i], nums);
        bool skip = solve(i+1,sum,nums);

        return dp[i][sum] = take || skip;
    }
    bool canPartition(vector<int>& nums) {
        n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum % 2 != 0) return false;
        int target = sum /2;
        dp.assign(n,vector<int>(target+1,-1));
        return solve(0,target,nums);
    }
};