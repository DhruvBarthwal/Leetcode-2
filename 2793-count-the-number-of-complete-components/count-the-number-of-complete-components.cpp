class Solution {
public:
vector<vector<int>> adj;
vector<bool> vis;
void dfs(int i,int &nodes, int &edges){
    vis[i] = true;
    nodes++;
    edges += adj[i].size();
    for(auto &neigh : adj[i]){
        if(!vis[neigh]) dfs(neigh, nodes,edges);
    }
}
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        adj.resize(n+1);
        for(auto &edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int components = 0;
        vis.resize(n+1,0);
        for(int i =0;i<n;i++){
            if (!vis[i]){
int nodes = 0, edges = 0;
            dfs(i,nodes,edges);
            edges /= 2;
            if(edges == nodes*(nodes - 1)/2) components++;
            }
        }
        return components;
    }
};