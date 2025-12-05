class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0LL);
        int n = nums.size();
        int left = 0, right  =0;
        int count = 0;
        for(int i=0;i<n-1;i++){
            left += nums[i];
            right = sum - left;
            if(abs(right - left)%2 == 0) count++;
        }
        return count;
    }
};