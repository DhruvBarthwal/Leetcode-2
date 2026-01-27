class Solution {
private:

public:
    int minCost(int n, vector<vector<int>>& edges) {
        //initialization
        vector<vector<pair<int,int>>>adj(n);
        //creating adj list
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,2*w});
        }

        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<>> pq;
        vector<bool> vis(n,false);
        vector<int> cost(n,INT_MAX);
        pq.push({0,0}); //{cost, node}
        int ans = 0;
        while(!pq.empty()){
            auto [cst, node] = pq.top();
            pq.pop();
            if(vis[node]) continue;
            vis[node] = true;
            for(auto [v, w] : adj[node]){
                if(cst + w < cost[v]){
                    cost[v] = cst+w;
                    pq.push({cost[v],v});
                }
            }
        }
        return cost[n-1] == INT_MAX ? -1 : cost[n-1];
    }
};