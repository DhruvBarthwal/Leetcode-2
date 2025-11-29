class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int value = accumulate(nums.begin(),nums.end(),0);
        return value % k;
    }
};