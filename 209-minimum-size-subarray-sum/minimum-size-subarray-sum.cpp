class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0;
        int n = nums.size();
        int prefix = 0, length = INT_MAX;
        for(int j = 0;j<n;j++){
            prefix += nums[j];

            while(prefix >= target){
                length = min(length, j-i+1);
                prefix -= nums[i];
                i++;
            }
        }
        return length == INT_MAX ? 0 : length;
    }
};