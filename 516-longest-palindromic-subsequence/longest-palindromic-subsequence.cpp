class Solution {
public:
    //global variable
    int n;
    vector<vector<int>>dp;

    int solve(int i, int j, string &s){
        //base case
        if(i > j) return 0;
        if(i == j) return 1;
        if(dp[i][j] != -1) return dp[i][j];

        int ans = 0;

        if(s[i] == s[j]){
            ans = 2 + solve(i+1,j-1,s);
        }  
        else{
            ans = max(solve(i+1,j,s),solve(i,j-1,s));
        }

        return dp[i][j] = ans;

    }

    int longestPalindromeSubseq(string s) {
        n = s.size();
        dp.assign(n+1,vector<int>(n+1,-1));

        return solve(0,n-1,s);
    }
};