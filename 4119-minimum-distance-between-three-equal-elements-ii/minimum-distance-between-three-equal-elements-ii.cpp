class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        if(n <=2) return -1;
        unordered_map<int,int> freq;
        unordered_map<int,vector<int>> mp;
        for(int i = 0;i<n;i++){
            freq[nums[i]]++;
        }
        for(int i=0;i<n;i++){
            if(freq[nums[i]] >= 3){
                mp[nums[i]].push_back(i);
            }
        }
        int mini = INT_MAX;
        for(auto [num,a] : mp){
            for(int idx = 0;idx < a.size()-2;idx++){
                int v1 = a[idx];
                int v2 = a[idx+1];
                int v3 = a[idx + 2];
                int value = abs(v1 - v2) + abs(v2 - v3) + abs(v3 - v1);
                mini = min(mini,value);
            }
        }
        return (mini == INT_MAX) ? -1 : mini;
    }
};