class Solution {
public:
    int solve(int i, int j , vector<int>&nums){
        int prev1 = 0, prev2 = 0;
        for(int start = i; i<=j ; i++){
            int curr = max(prev1 + nums[i], prev2);
            prev1 = prev2;
            prev2 = curr;
        }
        return prev2;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        int case1 = solve(0,n-2,nums);
        int case2 = solve(1, n-1, nums);
        int ans = max(case1, case2);
        return ans;
    }
};