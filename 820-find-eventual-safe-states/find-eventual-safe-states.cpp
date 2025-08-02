class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        //intialization
        int n = graph.size();
        unordered_map<int,list<int>> adj;
        unordered_map<int,int> outD;
        vector<int> ans ;
        vector<bool> vis(n,false);
        queue<int> q;
        //creating list
        for(int i = 0;i<n;i++){
            for(auto nums : graph[i]){
                adj[nums].push_back(i);
                outD[i]++;
            }
        }
        //outgoing nodes
        for(int i =0;i<n;i++){
            if(outD[i] == 0){
                q.push(i);
            }
        }

        //bfs traversal
        while(!q.empty()){
            int node = q.front();
            q.pop();
            vis[node] = true;
            for(auto neighbour : adj[node]){
                    outD[neighbour]--;
                    if(outD[neighbour] == 0){
                        q.push(neighbour);
                    }
            }
        }
        for(int i =0;i<n;i++){
            if(vis[i]){
                ans.push_back(i);
            }
        }
        return ans; 
    }
};