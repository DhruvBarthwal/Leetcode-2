class Solution {
public:
// int solve(int i, int j, int n, int m){
//     //base case
//     if(i == n-1 && j == m-1) return 1;
//     if(i >= n || j >= m) return 0;

//     if(dp[i][j] != -1) return dp[i][j];

//     int right = 0, bottom = 0;;
//     if(j < m) right = solve(i,j+1,n,m);
//     if(i < n) bottom = solve(i+1,j,n,m);

//     return dp[i][j] = right + bottom;
// }
    // vector<vector<int>>dp;
    // int uniquePaths(int m, int n) {
    // dp.assign(m,vector<int>(n,-1));
    //    return solve(0,0,m,n); 
    // }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,1));
        for(int i =1;i<m;i++){
            for(int j = 1;j<n;j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};