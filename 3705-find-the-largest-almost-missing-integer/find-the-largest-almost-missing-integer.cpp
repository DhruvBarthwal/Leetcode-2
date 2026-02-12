class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n = nums.size();
        for(int i =0;i<=n-k;i++){
            unordered_set<int>seen;
            for(int j = i;j<i+k;j++){
                seen.insert(nums[j]);
            }
            for(int x : seen){
                mp[x]++;
            }
        }
        int maxi = -1;
        for(auto &[it ,cnt] : mp){
            if(cnt == 1 ) maxi = max(maxi,it);
        }
        return maxi;
    }
};