class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        //initialization
        int n = nums.size();
        vector<int> dp(n,1);
        vector<int> count(n,1);
        int maxLen = 1;
        //traversing the array
        for(int i = 0;i<n;i++){
            for(int j = 0;j<i;j++){
                if(nums[j] < nums[i]){
                    if(dp[j]+1>dp[i]){
                        dp[i] = dp[j]+1;
                        count[i] = count[j];
                    }
                    else if(dp[j]+1 == dp[i]){
                        count[i]+= count[j];
                    }
                }
            }
            maxLen = max(maxLen, dp[i]);
        }
        int result = 0;
        for(int i = 0;i<n;i++){
            if(dp[i] == maxLen){
                result += count[i];
            }
        }
        return result;
    }
};