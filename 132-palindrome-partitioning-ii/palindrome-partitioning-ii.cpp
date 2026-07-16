class Solution {
public:
    //global variables
    int n;
    vector<int> dp;

    bool isPalindrome(string &s, int i, int j ){
        while(i < j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    int solve(int i, int j, string &s){
        //base case
        if(i >= j || isPalindrome(s,i,j)) return 0;
        if(dp[i] != -1) return dp[i];

        int mini = INT_MAX;

        for(int k = i;k<j;k++){
            if(isPalindrome(s,i,k)) {
                int ans = 1 + solve(k+1,j,s);
                mini = min(ans,mini);
            }
        }
        return dp[i] = mini;
    }

    int minCut(string s) {
        //initialization
        n = s.size();
        dp.assign(n,-1);

        if(isPalindrome(s,0,n-1)) return 0;
        return solve(0,n-1,s);
    }
};