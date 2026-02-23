class Solution {
public:
vector<vector<int>>dp;
int n , m;
    int solve(int i, int j, vector<vector<int>>&grid){
        if(i == n-1 && j == m-1) return grid[i][j];

        if(dp[i][j] != -1) return dp[i][j];

        int right= INT_MAX, bottom = INT_MAX;

        if(i+1 < n) bottom = solve(i+1,j,grid);
        if(j+1 < m) right = solve(i,j+1,grid);
        return dp[i][j] = grid[i][j] + min(right,bottom);
    }
    int minPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        dp.assign(n,vector<int>(m,-1));
        return solve(0,0,grid);
    }
};