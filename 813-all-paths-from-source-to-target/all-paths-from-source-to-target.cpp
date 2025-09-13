class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        int n = graph.size();
        //queue
        queue<pair<int,vector<int>>> q;
        q.push({0,{0}});
        while(!q.empty()){
            auto [u,ans] = q.front();
            q.pop();
            for(int v : graph[u]){
                vector<int> newPath = ans;
                newPath.push_back(v);
                if(v == n-1){
                    result.push_back(newPath);
                }
                else{
                    q.push({v,newPath});
                }
            }
        }
        return result;
    }
};