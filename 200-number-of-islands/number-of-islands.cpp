class Solution {
public:
//global variable
int rows , cols;
vector<vector<bool>> vis;  //visted 
vector<pair<int,int>> dir = {{0,1},{1,0},{-1,0},{0,-1}}; //direction

    void dfs(int row, int col, vector<vector<char>>&grid){
        //base case
        if(grid[row][col] == '0') return;
        vis[row][col] = true;

        for(auto &[dx,dy] : dir){
            int newRow = row + dx;
            int newCol = col + dy;
            //handling overflow
            if(newRow < 0 || newCol < 0 || newRow >= rows || newCol >= cols) continue;

            if(!vis[newRow][newCol]) dfs(newRow,newCol,grid);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        //intialization
        rows = grid.size(), cols = grid[0].size();
        vis.assign(rows,vector<bool>(cols,false));
        int islands = 0;

        //traverse the loop
        for(int row = 0;row< rows;row++){
            for(int col =0;col< cols;col++){
                if(!vis[row][col] && grid[row][col] == '1'){
                    //dfs
                    dfs(row,col,grid);
                    islands++;
                }
            }
        }

        //return ans
        return islands;
    }
};