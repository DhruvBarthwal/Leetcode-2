class Solution {
public:
vector<vector<int>>dp;
int n;
int solve(int i , int j, string &s){
    if(i>j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    char firstLetter = s[i];
    int ans = 1 + solve(i+1,j,s);
    for(int k = i+1;k<=j;k++){
        if(s[k] == firstLetter ){
            int newAns = solve(i,k-1,s) + solve(k+1,j,s);
            ans = min(ans,newAns);
        }
    }
    return dp[i][j] = ans;
}
    int strangePrinter(string s) {
      n = s.size();
      dp.assign(n,vector<int>(n,-1));
      return solve(0,n-1,s);  
    }
};