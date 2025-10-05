class Solution {
public:
    int n,m;
    void dfs(int i, int j, vector<vector<int>>&heights,vector<vector<bool>>& vis){
        vis[i][j] = true;
        for(auto [dx,dy] : dist){
            int x = i + dx;
            int y = j + dy;
            if(x>=0 && y>=0 && x<n && y<m && !vis[x][y] && heights[i][j] <= heights[x][y]){
                dfs(x,y,heights,vis);
            }
        }
    }
    vector<pair<int,int>>dist = {{0,1},{1,0},{0,-1},{-1,0}};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        //initialization
        n = heights.size();
        m = heights[0].size();
        vector<vector<bool>>pac(n,(vector<bool>(m,false)));
        vector<vector<bool>>atl(n,(vector<bool>(m,false)));
        //bottom
        for(int i =0;i<n;i++){
            dfs(i,0,heights,pac);
        }
        //left
        for(int j = 0;j<m;j++){
            dfs(0,j,heights,pac);
        }
        //top
        for(int i = 0;i<n;i++){
            dfs(i,m-1,heights,atl);
        }
        //right
        for(int j =0;j<m;j++){
            dfs(n-1,j,heights,atl);
        }
        vector<vector<int>>result;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(pac[i][j] && atl[i][j]){
                    result.push_back({i,j});
                }
            }
        }
        return result;
    }
};