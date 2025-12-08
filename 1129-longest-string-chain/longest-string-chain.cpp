class Solution {
public:
    int n;
    vector<int>dp;
    bool isSubsequence(string a, string b){
        if(a.length() + 1 != b.length()) return false;
        int i = 0, j  = 0;
        while(i<a.length() && j<b.length()){
            if(a[i] != b[j]){
                j++;
            }
            else{
                i++;
                j++;
            }
        }
        return i == a.length();
    }
    int solve(int i, vector<string>& words){
        //base case
        if(i == n) return 0;
        if(dp[i] != -1) return dp[i];

        int best = 1;
        for(int j = i+1;j<n;j++){
            if(words[i].size() + 1 == words[j].size() && isSubsequence(words[i],words[j])){
                best = max(best, 1+ solve(j,words));
            }
        }
        return dp[i] = best;

    }
    int longestStrChain(vector<string>& words) {
        n = words.size();
        dp.assign(n+1,-1);
        sort(words.begin(),words.end(),[](auto &a, auto &b){
            return a.size() < b.size();
        });
        int ans = 1;
        for(int i = 0;i<n;i++){
            ans = max(ans,solve(i,words));
        }
        return ans; 
    }
};