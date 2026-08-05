class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>&vis){
        vis[node] = true;
        for(auto &neigh : adj[node]){
            if(!vis[neigh]) dfs(neigh,adj,vis);
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n+1);
        for(auto &e : invocations){
            adj[e[0]].push_back(e[1]);
        }
        vector<bool> vis(n,false);
        vector<int> ans;
        dfs(k,adj,vis);

        for(auto &it : invocations){
            int u = it[0];
            int v = it[1];

            if(!vis[u] && vis[v]){
                for(int i = 0;i<n; i++){
                    ans.push_back(i);
                }
                return ans;
                
            }
        }

        for(int i =0;i<n;i++){
            if(!vis[i]) ans.push_back(i);
        }
        return ans;
    }
};