class Solution {
// private:
//     int solve(vector<int>&arr, int i, int prevIndex, vector<vector<int>>&dp, int difference){
//         //base case
//         if(i == arr.size()){
//             return 0;
//         }
//         if(dp[i][prevIndex+1] != -1){
//             return dp[i][prevIndex+1];
//         }
//         //skip
//         int skip = solve(arr,i+1, prevIndex,dp,difference);
//         //take
//         int take = 0;
//         if(prevIndex == -1 || arr[i] - arr[prevIndex] == difference){
//             take = 1 + solve(arr,i+1,i,dp,difference);
//         }
//         //return
//         return dp[i][prevIndex+1] = max(skip,take);
//     }
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        //initialization
        int n = arr.size();
        // vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        // return solve(arr,0,-1,dp,difference);
        unordered_map<int,int>dp;
        int maxi = 0;
        for(int num : arr){
            dp[num] = dp[num - difference] + 1;
            maxi = max(maxi,dp[num]);
        }
        return maxi;
    }
};