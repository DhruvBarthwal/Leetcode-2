class Solution {
private: 
    void dfs(int node, int parent,unordered_map<int,list<pair<int,bool>>>&adj,int &count){
        for(auto [neighbour, isOrignal] : adj[node]){
            if(neighbour == parent){
                continue;
            }
            if(isOrignal){
                count++;
            }
            dfs(neighbour, node,adj,count);
        }
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        //initialization
        int count = 0;
        unordered_map<int,list<pair<int,bool>>>adj;
        for(auto num : connections){
            int u = num[0];
            int v = num[1];
            adj[u].push_back({v,true});
            adj[v].push_back({u,false});
        }
        //dfs
        dfs(0,-1,adj,count);
        return count;
    }
};