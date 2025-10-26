class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0] = 1;
        int n = nums.size();
        int prefix = 0, count = 0;
        for(int i = 0;i<n;i++){
            prefix += nums[i];

            if(mp.count(prefix - k)){
                count += mp[prefix-k];
            }
            mp[prefix]++;
        }
        return count;
    }
};