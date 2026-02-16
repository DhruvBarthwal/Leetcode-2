class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int currMax = 0 , maxSum = nums[0], currMin = 0,minSum = nums[0];
        int total = 0;
        for(int x : nums){
            currMax = max(x, currMax + x);
            maxSum = max(currMax, maxSum);

            currMin = min(x, currMin + x);
            minSum = min ( currMin, minSum);

            total += x;
        }
        if(maxSum < 0) return maxSum;
        return max(maxSum, total - minSum);
    }
};