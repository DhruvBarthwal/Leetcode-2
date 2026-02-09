class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int,int>>> adj(n);
        for(int i  = 0;i<n-1;i++){
            for(int j =i+1;j<n;j++){
                int w = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                adj[i].push_back({j,w});
                adj[j].push_back({i,w});
            }
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        vector<bool> vis(n,false);
        int mst = 0;
        pq.push({0,0});
        while(!pq.empty()){
            auto [weight, u] = pq.top();
            pq.pop();
            if(vis[u]) continue;
            mst += weight;
            vis[u] = true;
            for(auto &[v,w] : adj[u]){
                if(!vis[v]){
                    pq.push({w,v});
                }
            }
        }
        return mst;
    }
};