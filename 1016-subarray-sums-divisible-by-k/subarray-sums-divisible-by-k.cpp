class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0] = 1;
        int curr = 0;
        int cnt = 0;
        int n = nums.size();
        for(int i =0;i<n;i++){
            curr += nums[i];
            int temp = curr % k;
            if(temp < 0) temp +=k;
            if(mp.count(temp)){
                cnt += mp[temp];
            }
            mp[temp]++;
        }   
        return cnt;
    }
};