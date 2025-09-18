class Solution {
    int n, m;
private:
    int dfs(int i, int j ,vector<vector<int>>&grid){
        //intialization
        vector<pair<int,int>> dis = {{0,1},{1,0},{0,-1},{-1,0}};
        //base case
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j] == 0){
            return 0;
        }
        //visited
        grid[i][j] = 0;
        int area = 1;

        for(auto [dx,dy] : dis){
            area += dfs(i+dx,j+dy,grid);
        }
        return area;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        //intialization
        int area = 0;
        n = grid.size(), m = grid[0].size();
        //traversing the grid
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 1 ){
                    area = max(area,dfs(i,j,grid));
                }
            }
        }
        return area;
    }
};