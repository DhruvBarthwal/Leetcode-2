class Solution {
public:
    //global variables
    vector<vector<long long>>dp;
    int n, m;

    // int solve(int i, int j, string&s, string&t){
    //     //base case
    //     if(j == m) return 1;
    //     if(i == n && j < m) return 0;

    //     if(dp[i][j] != -1) return dp[i][j];

    //     int skip = solve(i+1,j,s,t);
    //     int take = 0;
    //     if(s[i] == t[j]) take = solve(i+1,j+1,s,t);

    //     return dp[i][j] = take + skip; 
    // }

    // int numDistinct(string s, string t) {
    //     //initialization
    //     n = s.length();
    //     m = t.length();

    //     //edge case
    //     if(n < m) return 0;

    //     dp.assign(n+1,vector<int>(m+1,-1));

    //     return solve(0,0,s,t);
    // }

        int numDistinct(string s, string t) {
        //initialization
        n = s.length();
        m = t.length();

        //edge case
        if(n < m) return 0;

        dp.assign(n+1,vector<long long>(m+1,0));

        for(int i = 0;i<=n;i++){
            dp[i][m] = 1;
        }

        for(int i = n-1;i>=0;i--){
            for(int j =m-1;j>=0;j--){
                dp[i][j] = dp[i+1][j];
                
                if(s[i] == t[j]) dp[i][j] += dp[i+1][j+1];

                if(dp[i][j] > INT_MAX) dp[i][j] = INT_MAX;
            }
        }
        return dp[0][0];
    }
};