class Solution {
public:
int  n , m;
vector<vector<int>> dp;
    int solve(int i, int j, vector<vector<int>>&nums){
        if(i == n-1 && j == m-1) return 1;
        if(i >= n || j >= m) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int right = 0, bottom = 0;
        if(i < n && nums[i][j] == 0) right = solve(i+1,j,nums);
        if(j < m && nums[i][j] == 0) bottom = solve(i,j+1,nums);
        return dp[i][j] = right + bottom;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        n = obstacleGrid.size();
        m = obstacleGrid[0].size();
        if(obstacleGrid[n-1][m-1] == 1) return 0;
        dp.assign(n,vector<int>(m,-1));
        return solve(0,0,obstacleGrid);
    }
};