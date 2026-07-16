class Solution {
public:
    //global variables
    int n;
    vector<vector<int>>dp;

    int solve(int i, int prev, vector<int> &nums){
        //base case
        if(i == n) return 0;
        if(dp[i][prev+1] != -1) return dp[i][prev+1];

        int skip = solve(i+1,prev,nums);

        int take = 0;
        if(prev == -1 || (prev != -1 && (nums[i] % nums[prev] == 0))){
            take = 1 + solve(i+1,i,nums);
        }

        return dp[i][prev+1] = max(take,skip);
    }
    
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        //initialization
        n = nums.size();
        dp.assign(n,vector<int>(n+1,-1));

        //Sort the array
        sort(nums.begin(),nums.end());

        solve(0,-1,nums);

        vector<int> ans;
        int prev = -1;

        for(int i = 0;i<n;i++){
            if(prev == -1 || (prev != -1 && (nums[i] % nums[prev] == 0))){
                if(1 + solve(i+1,i,nums) >= solve(i+1,prev,nums)){
                    ans.push_back(nums[i]);
                    prev = i;
                }
            }
        }
        
        return ans;
    }
};