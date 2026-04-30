class Solution {
public:
    int n, m;
    vector<vector<vector<int>>> dp;
    vector<int> cost = {0,1,1};

    int solve(int i, int j, int k, vector<vector<int>>& grid){
        if(i >= n || j >= m) return -1e9;

        int c = cost[grid[i][j]];
        if(k < c) return -1e9;

        if(i == n-1 && j == m-1)
            return grid[i][j];

        if(dp[i][j][k] != -1) return dp[i][j][k];

        int newK = k - c;

        int down = solve(i+1, j, newK, grid);
        int right = solve(i, j+1, newK, grid);

        int ans = -1e9;

        if(down != -1e9)
            ans = max(ans, grid[i][j] + down);

        if(right != -1e9)
            ans = max(ans, grid[i][j] + right);

        return dp[i][j][k] = ans;
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();

        dp.assign(n, vector<vector<int>>(m, vector<int>(k+1, -1)));

        int ans = solve(0,0,k,grid);

        return ans < 0 ? -1 : ans;
    }
};