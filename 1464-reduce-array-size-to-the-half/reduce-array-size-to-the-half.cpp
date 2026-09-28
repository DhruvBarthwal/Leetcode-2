class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> mp;
        int n = arr.size();
        int size = n;

        for(int &x : arr) mp[x]++;

        priority_queue<int> pq;

        for(auto &[x,y] : mp) pq.push(y);

        int cnt = 0;

        while(!pq.empty()){
            int top = pq.top();
            pq.pop();
            size -= top;
            cnt++;
            if(size <= n/2) break;
        }

        return cnt;
    }
};