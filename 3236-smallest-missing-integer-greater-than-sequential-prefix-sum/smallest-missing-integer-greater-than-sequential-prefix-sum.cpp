class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int maxSum = nums[0];
        unordered_set<int> mp(nums.begin(),nums.end());
        for(int i =1;i<n;i++){
            if(nums[i] == nums[i-1] + 1) maxSum += nums[i];
            else break;
        }
        while (mp.count(maxSum)) {
            maxSum++;
        }
        return maxSum;
    }
};