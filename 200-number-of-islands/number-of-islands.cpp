class Solution {
public:
    //global variables
    int n, m;
    vector<vector<bool>> vis;
    vector<pair<int,int>> dis = {{0,1},{1,0},{0,-1},{-1,0}};

    void dfs(int i, int j, vector<vector<char>>&grid){
        if(grid[i][j] == '0') return;
        vis[i][j] = true;

        for(auto &[dx,dy] : dis){
            int x = i + dx, y = j + dy;
            if(x < 0 || x >=n || y<0 || y >=m) continue;
            if(!vis[x][y]) dfs(x,y,grid);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        n = grid.size(), m = grid[0].size();
        vis.assign(n,vector<bool>(m,false));
        int cnt = 0;

        for(int i =0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    dfs(i,j,grid);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};