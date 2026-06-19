class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            mp[nums[i]]++;
        }      
        priority_queue<pair<int,int>> pq;
        for(auto &[x,y] : mp){
            pq.push({y,x});
        }
        vector<int> ans;
        while(!pq.empty() && k--){
            auto num = pq.top();
            pq.pop();
            ans.push_back(num.second);
        }
        return ans;
    }
};