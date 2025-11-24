class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int,vector<pair<int,double>>> adj;
        for(int i = 0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            double w = succProb[i];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        queue<pair<int,double>>q;
        q.push({start_node,1.0});
        vector<double>prob(n,0);
        while(!q.empty()){
            auto [currNode , w] = q.front();
            q.pop();
            for(auto [v , W] : adj[currNode]){
                if(w * W > prob[v]){
                    prob[v] = w * W;
                    q.push({v,prob[v]});
                }
            }
        }
        return prob[end_node];
    }
};