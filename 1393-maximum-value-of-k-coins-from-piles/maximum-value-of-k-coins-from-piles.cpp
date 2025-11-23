class Solution {
public:
int n;
vector<vector<int>>dp;
int solve(int i, int k, vector<vector<int>>&piles){
    //base case
    if(i == n || k == 0) return 0;
    if(dp[i][k] != -1) return dp[i][k];

    int best = solve(i+1,k,piles);
    int prefix = 0;
    for(int idx = 0;idx < piles[i].size() && idx<k ;idx++){
        prefix += piles[i][idx];
        best = max(best,prefix + solve(i+1, k-idx-1,piles));
    }
    return dp[i][k] = best;
}
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        n = piles.size();
        dp.assign(n+1,vector<int>(k+1,-1));
        return solve(0,k, piles);
    }
};