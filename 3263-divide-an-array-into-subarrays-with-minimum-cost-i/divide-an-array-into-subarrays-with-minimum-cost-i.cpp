class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        int val = nums[0];
        sort(nums.begin()+1,nums.end());
        return val + nums[1] + nums[2];

    }
};