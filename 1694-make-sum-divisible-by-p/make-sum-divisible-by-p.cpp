class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long totalSum = accumulate(nums.begin(),nums.end(),0LL);
        unordered_map<int,int>mp;
        int n = nums.size();
        int target = totalSum % p;
        if(target == 0) return 0;
        mp[0] = -1;
        int currSum =0, length = n;
        for(int i =0;i<n;i++){
            currSum  = (currSum + nums[i]) % p;
            int needed = (currSum - target + p)%p;
            if(mp.count(needed)){
                length = min(length, i - mp[needed]);
            }
            mp[currSum] = i;
        }
    return length == n? -1 : length;
    }
};