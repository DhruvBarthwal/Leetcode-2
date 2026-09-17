class Solution {
public:
    //global initialization
    int n;
    vector<int>dp;

    int solve(int i, int steps, vector<int>&nums){
        //base case
        if(i >= n) return 0;
        if(i == n-1) return 1;
        if(dp[i] != -1) return dp[i];

        int ans = 0;
        for(int j = i+1;j<=i+nums[i] && j < n;j++){
            ans |= solve(j,nums[j],nums);
        }
        return dp[i] = ans;
    }

    bool canJump(vector<int>& nums) {
        //initialization
        n = nums.size();
        dp.assign(n+1,-1);

        int ans =solve(0,nums[0],nums);
        return ans == 0 ? false : true;
    }
};