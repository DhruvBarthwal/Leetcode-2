class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        bool hasNonZero = false;
        int mask = 0;
        
        for(int x: nums){
            mask ^= x;
            if(x != 0) hasNonZero = true;
        }
        if(mask != 0) return n;
        if(hasNonZero) return n-1;
        return 0;
    }
};