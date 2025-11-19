class Solution {
public:
const int M = 1e9 + 7;
vector<vector<long long>> dp;
long long solve(int i, int j,int n){
    //base case
    if(i == n) return 1;
    if(dp[i][j] != -1) return dp[i][j];

    long long a = solve(i+1,0,n);
    long long e = solve(i+1,1,n);
    long long I = solve(i+1,2,n);
    long long o = solve(i+1,3,n);
    long long u = solve(i+1,4,n);

    long long ans = 0;

    if(j == 0) ans = (e % M);
    else if(j == 1)  ans = (a + I) % M;
    else if(j == 2) ans = (a + e + o + u) % M;
    else if(j == 3) ans = (I + u) % M;
    else if(j == 4) ans = (a) % M;
    
    return dp[i][j] = ans;
}
    int countVowelPermutation(int n) {
        dp.assign(n+1,vector<long long>(5,-1));
        long long ans = 0;
        for(int i = 0;i<5;i++){
            ans = (ans + solve(1,i,n)) % M;
        }
        return ans;
    }
};