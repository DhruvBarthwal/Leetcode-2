class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& connections) {
        int m = connections.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<>> pq;
        unordered_map<int,vector<pair<int,int>>> adj(n+1);
        for(auto edge : connections){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});

        }
        vector<bool> vis(n+1,0);
        pq.push({0,1});
        int visCount = 0;
        long long mstWeight = 0;
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