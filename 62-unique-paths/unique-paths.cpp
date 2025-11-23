class Solution {
public:
int N ,M;
vector<vector<int>>dp;
int solve(int i, int j){
    //base case
    if(i == N-1 && j == M-1) return 1;
    if( i >= N || j >= M) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    int bottom = solve(i+1,j);
    int right = solve(i,j+1);
    return dp[i][j] = bottom + right;
}
    int uniquePaths(int m, int n) {
        N = m, M = n;
        dp.assign(N,vector<int>(M,-1));
        return solve(0,0);
    }
};