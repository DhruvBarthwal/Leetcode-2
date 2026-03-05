class Solution {
public:
int n, m;
    int orangesRotting(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        int time = 0;
        int cnt =0;
        queue<tuple<int,int,int>> q;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({i,j,0});
                    vis[i][j] = true;
                }
                else if(grid[i][j] == 1) cnt++;
            }
        }
        if(cnt == 0) return 0;
        vector<pair<int,int>> dis = {{0,1},{1,0},{-1,0},{0,-1}};
        while(!q.empty()){
            auto [x,y,t] = q.front();
            q.pop();
            time = max(time,t);
            for(auto &[dx,dy] : dis){
                int i = x + dx;
                int j = y + dy;
                if(i >= 0 && j >= 0 && i <n && j< m && vis[i][j] == false && grid[i][j] == 1){
                    cnt--;
                    vis[i][j] = true;
                    q.push({i,j,t+1});
                }
            }
        }
        return (cnt == 0) ? time : -1;
    }
};