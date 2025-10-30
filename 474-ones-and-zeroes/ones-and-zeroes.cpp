class Solution {
public:
vector<int>zeros, ones;
int solve(int i, int size, int m, int n, vector<vector<vector<int>>> & dp){
    //base case
    if(i == size || (m==0 && n==0)) return 0;
    if(dp[i][m][n] != -1)  return dp[i][m][n];

    if(zeros[i] > m || ones[i] > n){
        return solve(i+1,size,m,n,dp);
    }

    int take = 1 + solve(i+1, size,m-zeros[i],n-ones[i],dp);
    int skip = solve(i+1,size,m,n,dp);
    return dp[i][m][n] = max(take,skip);
}
    int findMaxForm(vector<string>& strs, int m, int n) {
        //initialization
        int size = strs.size();
        vector<vector<vector<int>>>dp(size+1,vector<vector<int>>(101,vector<int>(101,-1)));
        for(string num : strs){
            int zero =0, one = 0;
            for(char ch : num){
                if(ch == '1') one++;
                else zero++;
            }
            zeros.push_back(zero);
            ones.push_back(one);
        }
        return solve(0,size,m,n,dp);
    }
};