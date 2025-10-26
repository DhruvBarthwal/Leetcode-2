class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n = nums.size();
        int prefix = 0;
        mp[0] = -1;
        for(int i =0;i<n;i++){
            prefix += nums[i];
            if(mp.count(prefix % k)){
                if(i - mp[prefix%k] >= 2){
                    return true;
                }
            }
            else{
                mp[prefix % k] = i;
            }
        }
        return false;
    }
};