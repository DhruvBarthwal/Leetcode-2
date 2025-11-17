class Solution {
public:
vector<int> dp;
int solve(int n){
    //base case
    if(n <=1) return 1;
    if(dp[n] != -1) return dp[n];

    int ways = 0;
    for(int root = 1;root<=n;root++){
        int left = root-1;
        int right = n - root;
        ways += solve(left) * solve(right);
    }
    return dp[n] = ways;
}
    int numTrees(int n) {
        dp.assign(n+1,-1);
        return solve(n);
    }
};