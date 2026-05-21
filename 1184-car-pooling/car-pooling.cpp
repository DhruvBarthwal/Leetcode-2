class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(),trips.end(),[](vector<int>&a, vector<int>&b){
            if(a[1] == b[1]) return a[2] < b[2];
            return a[1] < b[1];
        });
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        
        for(auto &trip : trips){
            pq.push({trip[2],trip[0]});
        }
        int pass = 0;
        for(auto &trip : trips){
            pass += trip[0];
            while(!pq.empty() && pq.top().first <= trip[1]){
                pass -= pq.top().second;
                pq.pop();
            }
            if(pass > capacity) return false;     
        }
        return true;
    }
};