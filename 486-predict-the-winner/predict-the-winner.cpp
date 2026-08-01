class Solution {
public:
    vector<vector<int>> dp;
    int n;

    int solve(int i, int j,vector<int> &nums){
        if(i == j) return nums[i];

        if(dp[i][j] != -1) return dp[i][j];

        return dp[i][j] = max(nums[i] - solve(i+1,j,nums), nums[j] - solve(i,j-1,nums));
    }

    bool predictTheWinner(vector<int>& nums) {
        n = nums.size();

        if( n <= 2 || n % 2 == 0) return true;

        dp.assign(n+1,vector<int>(n+1,-1));

        return solve(0,n-1,nums) >= 0;
    }
};