class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int prev = 0;
        int curr = 1;
        int n = nums.size();
        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] < nums[i]) {
                curr++;
            } 
            else {
                prev = curr;
                curr = 1; 
            }
            ans = max(ans,min(prev,curr));
            ans = max(curr/2, ans);
        }
        return ans;
    }
};