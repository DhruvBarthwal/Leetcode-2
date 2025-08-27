class Solution {
private:
    int n,m;
    static constexpr int dir[4][2] = {{-1,1},{1,1},{1,-1},{-1,-1}};
    int dfs(int i , int j ,int dis,vector<vector<int>>&grid, bool turned,int num, vector<vector<vector<vector<int>>>>&dp){
        //base case
        if((i<0 || j<0 || i>=n || j>=m || grid[i][j] != num)){
            return 0;
        }
        int t = turned ? 1 : 0;

        if(dp[i][j][dis][t] != -1){
            return dp[i][j][dis][t];
        }
        int next_num = (num == 2) ? 0 : 2; 
        int res = dfs(i+dir[dis][0], j+dir[dis][1],dis,grid,turned,next_num,dp);

        if(!turned){
            int new_dir = (dis+1)%4;
            res = max(res, dfs(i+dir[new_dir][0], j+dir[new_dir][1],new_dir,grid,true,next_num,dp));
        }
        return dp[i][j][dis][t] = 1 + res;
        
    }
public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        //initialization
        n = grid.size(), m = grid[0].size();

        vector<vector<vector<vector<int>>>> dp(n+1,(vector<vector<vector<int>>>(m+1,vector<vector<int>>(4,vector<int>(2,-1)))));
        int maxi = 0;

        //pushing values = 1
        for(int i =0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 1){
                    for(int d = 0;d<4;d++){
                        int dx = dir[d][0], dy = dir[d][1];
                        int length = dfs(i+dx,j+dy,d,grid,0,2,dp) + 1;
                        maxi = max(maxi,length); 
                    }
                }
            }
        }
        return maxi;
    }
};