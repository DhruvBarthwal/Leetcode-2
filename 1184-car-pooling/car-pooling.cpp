class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(),trips.end(),[](vector<int>&a, vector<int>&b){
            if(a[1] == b[1]) return a[2] < b[2];
            return a[1] < b[1];
        });

        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        int space = 0;

        for(auto &t : trips){
            space += t[0];
            while(!pq.empty() && pq.top().first <= t[1]){
                space -= pq.top().second;
                pq.pop();
            }
            if(space > capacity) return false;
            pq.push({t[2],t[0]});        
        }
        return true;
    }
};