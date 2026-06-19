class Solution {
public:
    vector<vector<pair<int,int>>>adj;
    vector<int> ans;
    void dfs1(int node, int parent){
        for(auto &[neigh,cost] : adj[node]){
            if(neigh == parent) continue;
            ans[0] += cost;
            dfs1(neigh,node);
        }
    }
    void dfs2(int node, int parent){
        for(auto &[neigh,cost] : adj[node]){
            if(neigh == parent) continue;
            if(cost == 0) ans[neigh] = ans[node] + 1;
            else ans[neigh] = ans[node] -1;
            dfs2(neigh,node);
        }
    }
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        ans.resize(n);
        adj.resize(n);
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back({v,0});
            adj[v].push_back({u,1});
        }
        //computing root 0
        dfs1(0,-1);
        //computing other nodes
        dfs2(0,-1);
        return ans;
    }
};