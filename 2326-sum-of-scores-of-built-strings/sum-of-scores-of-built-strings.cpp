class Solution {
public:
using ll = long long;
vector<ll> solve(string &s){
    int n = s.size();
    int len = 0, i = 1;
    vector<ll> lps(n,0);
    while(i<n){
        if(s[i] == s[len]){
            lps[i] = len + 1;
            i++;
            len++;
        }
        else{
            if(len != 0){
                len = lps[len-1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}
    long long sumScores(string s) {
        int n = s.length();
        vector<ll> lps = solve(s);
        vector<ll> dp(n,0);
        ll ans = 0;
        for(int i = 0;i<n;i++){
            dp[i] = lps[i] == 0 ? 1 : dp[lps[i] - 1] + 1;
            ans += dp[i];
        }
        return ans;
    }
};