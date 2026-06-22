class Solution {
public:
unordered_map<string,bool> dp;
bool solve(string a, string b){
    if(a == b) return true;

    if(a.size() != b.size()) return false;

    string temp = a + "#" + b;
    if(dp.count(temp)) return dp[temp];

    int n = a.size();
    for(int k = 1;k<n;k++){
        bool unswap = solve(a.substr(0,k),b.substr(0,k)) && solve(a.substr(k),b.substr(k));
        bool swap = solve(a.substr(0,k),b.substr(n-k)) && solve(a.substr(k),b.substr(0,n-k));
        if(unswap || swap) return dp[temp] = true;
    }
    return dp[temp] = false;
}
    bool isScramble(string s1, string s2) {
        return solve(s1,s2);
    }
};