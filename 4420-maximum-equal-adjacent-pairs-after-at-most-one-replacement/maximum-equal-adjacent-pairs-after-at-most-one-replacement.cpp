class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        int n = nums.size();
        map<pair<int,int>,int>mp;
        int cnt = 0;
        for(int i = 1;i<n;i++){
            int a = nums[i-1];
            int b = nums[i];
            if(a == b) cnt++;
            else{
                mp[{b,a}]++;
                mp[{a,b}]++;

            }
        }
        int ans = 0;
        for(auto [x,y] : mp){
            ans = max(ans,y);
        }
        return ans + cnt;
    }
};