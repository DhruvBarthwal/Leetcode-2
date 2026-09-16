class Solution {
public:
    //global variable
    int n;
    vector<vector<int>>dp;

    // int solve(int i, int j, string &s){
    //     //base case
    //     if(i > j) return 0;
    //     if(i == j) return 1;
    //     if(dp[i][j] != -1) return dp[i][j];

    //     int ans = 0;

    //     if(s[i] == s[j]){
    //         ans = 2 + solve(i+1,j-1,s);
    //     }  
    //     else{
    //         ans = max(solve(i+1,j,s),solve(i,j-1,s));
    //     }

    //     return dp[i][j] = ans;

    // }

    // int longestPalindromeSubseq(string s) {
    //     n = s.size();
    //     dp.assign(n+1,vector<int>(n+1,-1));

    //     return solve(0,n-1,s);
    // }
    // int longestPalindromeSubseq(string s) {
    //     n = s.size();
    //     dp.assign(n+1,vector<int>(n+1,0));

    //     for(int i =0;i<n;i++){
    //         dp[i][i] = 1;
    //     }

    //     int ans = 0;
    //     for(int i = n-1;i>=0;i--){
    //         for(int j = i+1;j<n;j++){
    //             int ans =0;
    //             if(s[i] == s[j]) ans = 2 + dp[i+1][j-1];
    //             else ans = max(dp[i+1][j], dp[i][j-1]);
    //             dp[i][j] = ans;
    //         }
    //     }
    //     return dp[0][n-1];
    // }

    int longestPalindromeSubseq(string s) {
        n = s.size();
        if(n == 1) return 1;
        vector<int> curr(n+1,0);
        vector<int> next(n+1,0);

        for(int i =0;i<n;i++){
            next[i] = 1;
        }

        int ans = 0;
        for(int i = n-1;i>=0;i--){
            curr.assign(n+1,0);
            curr[i] = 1;
            for(int j = i+1;j<n;j++){
                int ans =0;
                if(s[i] == s[j]) ans = 2 + next[j-1];
                else ans = max(next[j], curr[j-1]);
                curr[j] = ans;
            }
            next = curr;
        }
        return next[n-1];
    }
};