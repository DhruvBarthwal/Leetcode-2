class Solution {
public:
vector<vector<vector<int>>>dp;
string num;
set<int> valid = {0,1,2,5,6,8,9};
set<int> change = {2,5,6,9};
int solve(int i, int tight, int changed){
    if(i == num.size()) return changed;

    if(dp[i][tight][changed] != -1) return dp[i][tight][changed];

    int res = 0;

    int limit = tight ? num[i] - '0' : 9;

    for(int j = 0;j<=limit;j++){
        if(valid.count(j) == 0) continue;

        int newTight = (tight && (j == limit)) ? 1 : 0;
        int newChanged = changed | change.count(j) ? 1 : 0;

        res += solve(i+1,newTight, newChanged);
    }

    return dp[i][tight][changed] = res;
}
    int rotatedDigits(int n) {
        num = to_string(n);
        dp.assign(20,vector<vector<int>>(2,vector<int>(2,-1)));
        return solve(0,1,0);
    }
};