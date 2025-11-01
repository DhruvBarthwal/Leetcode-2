class Solution {
public:
int n, m;
int dp[151][151];
const int M = 1e9 + 7;
int solve(int i, int GCD, vector<vector<int>> & mat){
    //base case
    if(i == n) return GCD == 1;
    if(dp[i][GCD] != -1) return dp[i][GCD];

    long long ways = 0;

    for(int x : mat[i]){
        int new_GCD = (GCD == 0) ? x : __gcd(x,GCD);
        ways = (ways + solve(i+1,new_GCD,mat)) % M;
    }
    return dp[i][GCD] = ways;
}
    int countCoprime(vector<vector<int>>& mat) {
        //initialization
        n = mat.size();
        m = mat[0].size();
        memset(dp ,-1, sizeof(dp));
        return solve(0,0,mat);
    }
};