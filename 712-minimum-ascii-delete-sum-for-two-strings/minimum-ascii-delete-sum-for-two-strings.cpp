class Solution {
public:
vector<vector<int>> dp;
int n, m;
// int solve(int i , int j, string s1, string s2){
//     //base case
//     if(i == n && j == m) return 0;
//     if(j == m && i<n){
//         int sum = 0;
//         for(int k = i;k<n;k++){
//             sum+=s1[k];
//         }
//         return sum;
//     }
//     if(i == n && j<m){
//         int sum = 0;
//         for(int k = j;k<m;k++){
//             sum+=s2[k];
//         }
//         return sum;
//     }
//     if(dp[i][j] != -1) return dp[i][j];

//     int ans = 0;
//     if(s1[i] == s2[j]) ans = solve(i+1, j+1, s1,s2);
//     else {
//         int skip1 = int(s1[i]) + solve(i+1,j,s1,s2);
//         int skip2 = int(s2[j]) + solve(i,j+1,s1,s2);
//         ans = min(skip1,skip2); 
//     }
//     return dp[i][j] = ans;
// }
    // int minimumDeleteSum(string s1, string s2) {
    //     n = s1.size(), m = s2.size();
    //     dp.assign(n+1,vector<int>(m+1,-1));
    //     return solve(0,0,s1,s2);
    // }
    int minimumDeleteSum(string s1, string s2) {
        n = s1.size(), m = s2.size();
        vector<int> curr(m+1,0);
        vector<int> next(m+1,0);
        for(int j = m-1;j>=0;j--){
            next[j] = next[j+1] +int(s2[j]);
        }
        for(int i = n-1;i>=0;i--){
            for(int j = m-1;j>=0;j--){
                curr[m] = next[m] + int(s1[i]);
                if(s1[i] == s2[j]){
                    curr[j] = next[j+1];
                }
                else{
                    int skip1 = int(s1[i]) +next[j];
                    int skip2 = int(s2[j]) + curr[j+1];
                    curr[j] = min(skip1,skip2); 
                }
            }
            next = curr;
        }
        return next[0];
    }
};