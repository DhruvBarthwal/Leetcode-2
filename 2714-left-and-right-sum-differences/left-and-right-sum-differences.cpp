class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        long long sum = accumulate(nums.begin(),nums.end(),0);
        int leftsum = 0;
        int n = nums.size();
        vector<int> ans;
        for(int i = 0;i<n;i++){
            int rightSum = sum - leftsum - nums[i];
            ans.push_back(abs(leftsum - rightSum));
            leftsum += nums[i];
        }
        return ans;
    }
};