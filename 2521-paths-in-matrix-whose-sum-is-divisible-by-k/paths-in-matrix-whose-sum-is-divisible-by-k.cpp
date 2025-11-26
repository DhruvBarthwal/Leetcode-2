class Solution {
public:
const int M = 1e9 + 7;
long long n,m;
vector<vector<vector<long long>>>dp;
long long solve(long long i, long long j,long long r , vector<vector<int>>&grid, int k){
    //base case
    if(i == n-1 && j == m-1){
        int value = (r + grid[i][j]) % k;
        return value == 0 ? 1 : 0;
    }
    if(dp[i][j][r] != -1){
        return dp[i][j][r];
    }
    long long sum = (r + grid[i][j]) % k;
    long long ways = 0;
    if(j+1<m) ways = (ways + solve(i,j+1, sum, grid,k)) % M;
    if(i+1<n) ways = (ways + solve(i+1,j, sum, grid,k)) % M;

    return dp[i][j][r] = ways;
}
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();
        dp.assign(n,vector<vector<long long>>(m,vector<long long>(k,-1)));
        return solve(0,0,0,grid,k);
    }
};