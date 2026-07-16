class Solution {
public:
    //global variable
    int n;
    vector<vector<int>> dp;
    int solve(int i , int j, vector<int> &nums){
        //base case
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int ans = 0;
        for(int k = i;k<=j;k++){
            int mini = nums[i-1]*nums[k]*nums[j+1] + solve(i,k-1,nums) + solve(k+1,j,nums);
            ans = max(ans,mini);
        }
        return dp[i][j] = ans;
    }

    int maxCoins(vector<int>& nums) {
       //initialization
       n = nums.size();
       dp.assign(n+2,vector<int>(n+2,-1));
       
       nums.push_back(1);
       nums.insert(nums.begin(),1);

       return solve(1,n,nums); 
    }
};