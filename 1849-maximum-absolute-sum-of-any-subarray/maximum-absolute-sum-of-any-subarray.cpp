class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int currMax = 0 , maxSum = nums[0], currMin = 0, minSum = nums[0];
        for(int x : nums){
            currMax = max(x,currMax + x);
            maxSum = max(maxSum,currMax);

            currMin = min(currMin + x , x);
            minSum = min(minSum, currMin);
        }
        return max(maxSum, abs(minSum));
    }
};