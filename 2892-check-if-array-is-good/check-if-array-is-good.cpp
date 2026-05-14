class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(),nums.end());
        if(n != maxi + 1) return false;
        sort(nums.begin(),nums.end());
        for(int i =0;i<n-1;i++) if(nums[i] != i+1) return false;
        if(nums[n-1] != maxi) return false;
        return true;
    }
};