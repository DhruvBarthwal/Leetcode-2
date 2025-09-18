class Solution {
    int n, m;
private:
    bool dfs(int i, int j,vector<vector<int>>& grid){
        //intialization
        vector<pair<int,int>> dis = {{0,1},{1,0},{0,-1},{-1,0}};
        //base case
        if(i <0 || j<0 || i>=n || j>=m){
            return false;
        }
        if(grid[i][j] == 1){
            return true;
        }
        //visited
        grid[i][j] = 1;
        bool left = dfs(i,j-1,grid);
        bool right = dfs(i,j+1,grid);
        bool top = dfs(i-1,j,grid);
        bool bottom = dfs(i+1,j,grid);

        return left && right && top && bottom;
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        //initialization
        int count = 0;
        n = grid.size(), m = grid[0].size();
        //traversing the matrix
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 0 && dfs(i,j,grid)){
                    count++;
                }
            }
        }
        return count;
    }
};