class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int zeros = 0 , ones = 0;
        unordered_map<int,int> mp;
        int ans = 0;
        mp[0] = -1;
        for(int i =0;i<nums.size();i++){
            if(nums[i] == 0) zeros++;
            else ones++;
            int diff = zeros - ones;
            if(mp.count(diff)){
                ans = max(ans , i - mp[diff]);
            }
            else mp[diff] = i;
        }
        return ans;
    }
};