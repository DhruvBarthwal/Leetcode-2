class Solution {
public:
const int M = 1e9 + 7;
    long long memo(int n,vector<long long>&dp){
        //base case
        if(n == 0) return 1;
        if(n == 1) return 1;
        if(n == 2) return 2;
        if(dp[n] != -1){
            return dp[n];
        }

        return dp[n] = (2*(memo(n-1,dp))%M + memo(n-3,dp)%M)%M;
    }
    int numTilings(int n) {
        vector<long long> dp (n+1, -1);
        return memo(n,dp);
    }
};