class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
         vector<bool> ans;
         int n = nums.size();
         int value = 0;
         for(int i = 0;i<n;i++){
            value = ((value << 1) | nums[i]) % 5; 
            ans.push_back(value == 0);
         }
         return ans;
    }
};