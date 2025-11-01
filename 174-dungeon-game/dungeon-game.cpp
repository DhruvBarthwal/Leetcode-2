class Solution {
    int n, m;
    int dp[201][201];
public:
int solve(int i, int j, vector<vector<int>>& dungeon){
    //base case
    if(i == n || j == m) return 1e9;
    if(i == n-1 && j == m-1) return max(1,1-dungeon[i][j]);
    if(dp[i][j] != -1) return dp[i][j];

    //right 
    int right = solve(i,j+1,dungeon);
    //down
    int down = solve(i+1, j, dungeon);
    int need = min(right , down) - dungeon[i][j];
    return dp[i][j] = max(1,need);

}
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        n = dungeon.size(), m = dungeon[0].size();
        memset(dp, -1, sizeof(dp));
        return solve(0,0,dungeon);
    }
};