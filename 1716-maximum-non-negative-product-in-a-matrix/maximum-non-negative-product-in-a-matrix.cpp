class Solution {
public:
vector<vector<pair<long long ,long long>>> dp;
vector<vector<bool>> vis;
int n, m;
const int M = 1e9 + 7;
    pair<long long, long long> solve(int i , int j, vector<vector<int>>&grid){
        //base case
        if(i == n-1 && j == m-1) return {grid[i][j], grid[i][j]};
        if(vis[i][j]) return dp[i][j];

        long long maxi = LLONG_MIN;
        long long mini = LLONG_MAX;

        if(i < n-1){
            auto [dMaxi, dMini] = solve(i+1,j,grid);
            long long a = grid[i][j] * dMaxi;
            long long b = grid[i][j] * dMini;

            maxi = max({maxi, a , b});
            mini = min({mini, a , b});
        }   
        if(j < m-1){
            auto [rMaxi, rMini] = solve(i, j+1,grid);
            long long a = grid[i][j] * rMaxi;
            long long b = grid[i][j] * rMini;

            maxi = max({maxi, a, b});
            mini = min({mini, a ,b});
        }
        vis[i][j] = true;
        return dp[i][j] = {maxi , mini};
    }
    int maxProductPath(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        dp.assign(n,vector<pair<long long, long long>>(m));
        vis.assign(n, vector<bool>(m, false));
        auto [maxi , mini] = solve(0,0,grid);
        if(maxi < 0) return -1;
        return maxi % M;
    }
};