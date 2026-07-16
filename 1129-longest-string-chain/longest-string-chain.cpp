class Solution {
public:
    //global variable
    vector<int> dp;
    int n;

    bool isSubsequence(string&a, string&b){
        int i = 0, j =0;
        while(i < a.size() && j < b.size()){
            if(a[i] != b[j]) j++;
            else{
                i++;
                j++;
            }
        }
        return i == a.size();
    }

    int solve(int i, vector<string>&words){
        //base case
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];

        int ans = 1;

        for(int j = i+1;j<n;j++){
            if(words[i].size() + 1 == words[j].size() && isSubsequence(words[i],words[j])){
                ans = max(ans,1 + solve(j,words));
            }
        }

        return dp[i] = ans;
    }

    int longestStrChain(vector<string>& words) {
        //initialization
        n = words.size();
        dp.assign(n,-1);

        //sort the array
        sort(words.begin(),words.end(),[](string &a , string&b){
            return a.size() < b.size();
        });

        int ans = 1;
        for(int i =0;i<n;i++){
            ans = max(ans,solve(i,words));
        }
        return ans;
    }
};