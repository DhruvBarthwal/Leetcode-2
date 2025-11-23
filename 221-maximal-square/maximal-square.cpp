class Solution {
public:
int n , m;
vector<vector<int>> dp;
// int solve(int i , int j,vector<vector<char>>& matrix){
//     //base case
//     if(i >=n || j >=m) return 0;
//     if(dp[i][j] != -1) return dp[i][j];

//     int bottom = solve(i+1,j,matrix);
//     int right = solve(i,j+1,matrix);
//     int diag = solve(i+1, j+1,matrix);

//     if(matrix[i][j] == '1'){
//         return dp[i][j] = 1 + min({bottom,right,diag});
//     }
//     else{
//         return dp[i][j] = 0;
//     }
// }
//     int maximalSquare(vector<vector<char>>& matrix) {
//         n = matrix.size();
//         m = matrix[0].size();
//         dp.assign(n,vector<int>(m,-1));
//         int ans = 0;
//         for(int i = 0;i<n;i++){
//             for(int j = 0;j<m;j++){
//                 ans = max(ans,solve(i,j,matrix));
//             }
//         }
//         return ans*ans;
//     }
    int maximalSquare(vector<vector<char>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        dp.assign(n,vector<int>(m,0));
        int ans = 0;
        for(int i = 0;i<n;i++){
            if(matrix[i][0] == '1'){
                dp[i][0] = 1;
                ans = max(ans,dp[i][0]);  
            }

        }   
        for(int i = 0;i<m;i++){
            if(matrix[0][i] == '1') {
                dp[0][i] = 1;
                ans = max(ans,dp[0][i]);
            }
        }
        for(int i =1;i<n;i++){
            for(int j = 1;j<m;j++){
                if(matrix[i][j] == '1'){
                    dp[i][j] = 1 + min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
                }
                else{
                    dp[i][j] = 0;
                }
                ans = max(ans,dp[i][j]);
            }
        }
        return ans*ans;
    }
};