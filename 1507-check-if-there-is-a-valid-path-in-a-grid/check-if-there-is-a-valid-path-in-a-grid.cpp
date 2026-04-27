class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int n = grid.size(), m = grid[0].size();
        q.push({0,0});
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        vector<vector<pair<int,int>>> dir(7);
        dir[1] = {{0,-1},{0,1}};
        dir[2] = {{-1,0},{1,0}};
        dir[3] = {{0,-1},{1,0}};
        dir[4] = {{0,1},{1,0}};  
        dir[5] = {{0,-1},{-1,0}};  
        dir[6] = {{0,1},{-1,0}}; 
        vis[0][0] = true;
        while(!q.empty()){
            auto [i,j] = q.front();
            q.pop();
            if(i == n-1 && j == m-1) return true;
            for(auto &[dx,dy] : dir[grid[i][j]]){
                int x = i + dx;
                int y = j + dy;
                if(x < 0 || y < 0 || x >= n || y >= m) continue;
                if(vis[x][y]) continue;
                for(auto &[a,b] : dir[grid[x][y]]){
                    if(x + a == i && y + b == j){
                        vis[x][y] = true;
                        q.push({x,y});
                    }
                }
            }
        }
        return false;
    }
};