class Solution {
public:
    //global variable
    int n;
    vector<pair<int,int>> dp; //length , count

    pair<int,int> solve(int i, vector<int>& nums){
        //base case
        if(dp[i].first != -1) return dp[i];

        int maxLen = 1;
        int maxCnt = 1;

        for(int j = i+1;j<n;j++){
            if(nums[i] < nums[j]){
                auto [len , cnt] = solve(j,nums);

                if(len + 1  > maxLen){
                    maxLen = 1 + len;
                    maxCnt = cnt;
                }
                else if(1 + len == maxLen){
                    maxCnt += cnt;
                }
            }
        }
        return dp[i] = {maxLen,maxCnt};
    }

    int findNumberOfLIS(vector<int>& nums) {
        //intialization
        n = nums.size();
        dp.assign(n,{-1,-1});
        
        int LIS = 0;
        int ans = 0;
        //calculating max subsequence
        for(int i = 0;i<n;i++){
            auto [len,cnt] = solve(i,nums);

            if(len > LIS){
                LIS = len;
                ans = cnt;
            }
            else if(len == LIS){
                ans += cnt;
            }
        }

        return ans;
    }
};