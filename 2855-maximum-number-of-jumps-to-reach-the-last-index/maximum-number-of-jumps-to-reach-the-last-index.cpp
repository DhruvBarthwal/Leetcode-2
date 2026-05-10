class Solution {
public:
    
    vector<int> dp;
    int n;

    int solve(int i, vector<int>& nums, int target) {

        if(i == n - 1)
            return 0;

        if(dp[i] != INT_MAX)
            return dp[i];

        int ans = -1;

        for(int j = i + 1; j < n; j++) {

            if(abs(nums[j] - nums[i]) <= target) {

                int val = solve(j, nums, target);

                if(val != -1)
                    ans = max(ans, 1 + val);
            }
        }

        return dp[i] = ans;
    }

    int maximumJumps(vector<int>& nums, int target) {

        n = nums.size();

        dp.assign(n, INT_MAX);

        int ans = solve(0, nums, target);
        return ans == INT_MAX ? -1 : ans;
    }
};