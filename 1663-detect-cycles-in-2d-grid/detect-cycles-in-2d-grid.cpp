class Solution {
public:
    int n , m;
    vector<pair<int,int>>dist = {{0,1},{1,0},{0,-1},{-1,0}};
    bool bfs(int i, int j,vector<vector<char>>& grid, vector<vector<bool>>& vis){
        queue<pair<pair<int,int>,pair<int,int>>> q;
        q.push({{i,j},{-1,-1}});

        while(!q.empty()){
            auto curr = q.front();
            int i = curr.first.first;
            int j = curr.first.second;
            int nx = curr.second.first;
            int ny = curr.second.second;
            q.pop();
            if(vis[i][j]) continue;
            vis[i][j] = true;
            for(auto &[dx,dy] : dist){
                int x = i + dx;
                int y = j + dy;
                if(x < 0 || x >= n || y < 0 || y >= m) continue;
                if(grid[x][y] != grid[i][j]) continue;
                if(nx == x && ny == y) continue;
                if(vis[x][y]) return true;
                q.push({{x,y},{i,j}});
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid){
        n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(!vis[i][j]){
                    if(bfs(i,j,grid,vis)) return true;
                }
            }
        }
        return false;
    }
};