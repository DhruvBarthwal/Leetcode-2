class Solution {
public:

    int orangesRotting(vector<vector<int>>& grid) {
        //intialization
        int rows = grid.size(), cols = grid[0].size();
        int time = 0, cntFreshOranges = 0, finalTime = 0;
        queue<tuple<int,int,int>> q; //row, col, time
        vector<pair<int,int>> dir = {{1,0},{0,1},{-1,0},{0,-1}}; //directions
        vector<vector<bool>> vis(rows,vector<bool>(cols,false));

        //traverse the grid
        for(int row =0;row<rows;row++){
            for(int col =0;col<cols;col++){
                if(grid[row][col] == 1) cntFreshOranges++;
                else if(grid[row][col] == 2) q.push({row,col,0});
            }
        }

        //edge case
        if(cntFreshOranges == 0) return 0;

        //bfs
        while(!q.empty()){
            auto [i,j,t] = q.front(); // currRow, currCol, currTime
            q.pop();
            
            finalTime = max(finalTime, t);

            for(auto &[dx,dy] : dir){
                int newRow = i + dx;
                int newCol = j + dy;

                if(newRow < 0 || newCol < 0 || newRow >= rows || newCol >= cols || grid[newRow][newCol] != 1) continue;
                if(vis[newRow][newCol]) continue;

                cntFreshOranges--;
                vis[newRow][newCol] = true;

                q.push({newRow,newCol,t+1});
            }
        }
        return cntFreshOranges == 0 ? finalTime : -1;
    }
};