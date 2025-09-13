class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        //intialization
        unordered_map<int, list<int>>redAdj(n), blueAdj(n);
        vector<vector<int>> dis(n, vector<int>(2,INT_MAX));
        queue<pair<int,int>> q;
        vector<int> result(n);
        //creating adj list
        for(auto num : redEdges){
            int u = num[0];
            int v = num[1];
            redAdj[u].push_back(v);
        }
        for(auto num : blueEdges){
            int u = num[0];
            int v = num[1];
            blueAdj[u].push_back(v);
        }
        //queue
        q.push({0,0}); //red
        q.push({0,1}); //blue

        dis[0][0] = dis[0][1] = 0;
        while(!q.empty()){
            auto [u, color] = q.front();
            q.pop();
            int d = dis[u][color];
            if(color == 0){
                for(int v : blueAdj[u]){
                    if(dis[v][1] == INT_MAX){
                        dis[v][1] = d+1;
                        q.push({v,1});
                    }
                }
            }
            else{
                for(int v : redAdj[u]){
                    if(dis[v][0] == INT_MAX){
                        dis[v][0] = d+1;
                        q.push({v,0});
                    }
                }
            }
        }
        for(int i = 0;i<n;i++){
            int best = min(dis[i][0],dis[i][1]);
            result[i] = (best == INT_MAX ? -1 : best);
        }
        return result;
    }
};