class Solution {
public:
bool isPalindrome(string &st, int i , int j){
    while(i<j){
        if(st[i] != st[j]) return false;
        i++;
        j--;
    }
    return true;
}
int solve(int i ,int j,string s, vector<int>&dp){
    //base case
    if(i >= j || isPalindrome(s,i,j)) return 0;

    if(dp[i] != -1) return dp[i];

    int mini = INT_MAX;

    for(int k = i;k<j;k++){
        if(isPalindrome(s,i,k)){
            int ans = 1 +solve(k+1,j,s,dp) ;
            mini = min(ans,mini);
        }
    }
    return dp[i] = mini;
}
    int minCut(string s) {
        int n = s.size();
        vector<int>dp(n+1,-1);
        if(isPalindrome(s,0,n-1)) return 0;
        return solve(0,n-1,s,dp);
    }
};