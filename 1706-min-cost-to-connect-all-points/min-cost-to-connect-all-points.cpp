class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        unordered_map<int, vector<pair<int,int>>> adj;
        int n = points.size();
        for(int i = 0;i<n;i++){
            for(int j =i+1;j<n;j++){
                int w = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                adj[i].push_back({j,w});
                adj[j].push_back({i,w});
            }
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>>pq;
        int mstWeight = 0;
        int visCount = 0;
        vector<bool> vis(n,false);
        pq.push({0,0});
        while(!pq.empty()){
            auto [w,u] = pq.top();
            pq.pop();
            if(vis[u]) continue;
            vis[u] = true;
            visCount++;
            mstWeight += w;
            for(auto [v,weight] : adj[u]){
                if(!vis[v]){
                    pq.push({weight,v});
                }
            }
        }
        if(visCount != n) return -1;
        return mstWeight;
    }
};