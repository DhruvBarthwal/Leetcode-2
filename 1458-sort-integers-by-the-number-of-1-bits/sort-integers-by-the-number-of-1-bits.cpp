class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        int n = arr.size();
        for(int i =0;i<n;i++){
            int val = __builtin_popcount(arr[i]);
            pq.push({val,arr[i]});
        }
        vector<int> ans;
        while(!pq.empty()){
            auto [val,num] = pq.top();
            pq.pop();
            ans.push_back(num);
        }
        return ans;
    }
};