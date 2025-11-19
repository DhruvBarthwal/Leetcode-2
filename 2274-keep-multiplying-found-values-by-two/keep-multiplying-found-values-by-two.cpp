class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_map<int,int> mp;
        int n = nums.size();
        for(int num : nums){
            mp[num]++;
        }
        int target = original;
        while(mp.count(target)){
            target *=2;
        }
        return target;
    }
};