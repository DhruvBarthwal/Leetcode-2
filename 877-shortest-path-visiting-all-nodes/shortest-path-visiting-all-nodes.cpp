class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        //Initialization
        int n = graph.size();
        int finalMask = (1 << n) - 1;

        queue<pair<int,int>>q;
        vector<vector<bool>> vis((1 << n),vector<bool>(n,0));
        
        for(int i =0;i<n;i++){
            int mask = 1 << i;
            q.push({mask,i});  
            vis[mask][i] = true;
        }

        int steps = 0;

        //BFS
        while(!q.empty()){
            int sz = q.size();

            while(sz--){
                auto [mask , node] = q.front();
                q.pop();

                if(mask == finalMask) return steps;

                for(auto &neigh : graph[node]){
                    int newMask = mask | (1 << neigh);

                    if(!vis[newMask][neigh]){
                        vis[newMask][neigh] = true;
                        q.push({newMask,neigh});
                    }
                }
            } 

            steps++;
        }

        return -1;
    }
};