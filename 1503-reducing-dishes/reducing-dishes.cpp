class Solution {
public:
    //global variables
    int n;
    vector<vector<int>> dp;

    int solve(int i, int k, vector<int>&nums){
        //base case
        if(i == n) return 0;
        if(dp[i][k] != -1) return dp[i][k];

        int skip = solve(i+1,k,nums);
        int take = nums[i] * k + solve(i+1,k+1,nums);

        return dp[i][k] = max(skip,take);
    }

    int maxSatisfaction(vector<int>& satisfaction) {
        //initialization
        n = satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());
        dp.assign(n,vector<int>(n+1,-1));

        int ans = 0;
        for(int i =0;i<n;i++){
            ans = max(ans,solve(i,1,satisfaction));
        }

        return ans;
    }
};