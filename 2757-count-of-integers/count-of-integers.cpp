class Solution {
public:
    long long dp[24][2][210];
    const int M = 1e9+7;
    int mini, maxi;
    string subtract(string s){
        int i = s.size()-1;
        while(i>=0 && s[i] == '0'){
            s[i] = '9';
            i--;
        }
        if(i>=0) s[i]--;
        int pos = 0;
        while(pos + 1 < s.size() && s[pos] == '0'){
            pos++;
        }
        return s.substr(pos);
    }
    long long solve(int pos,int tight, long long sum, string &s, int m){
        if(pos == m){
            if(sum >= mini && sum <= maxi) return 1;
            else return 0;
        }
        if(dp[pos][tight][sum] != -1) return dp[pos][tight][sum];

        int limit = tight ? s[pos] - '0' : 9;
        long long ans = 0;
        for(int d = 0;d<=limit;d++){
            ans = (ans + solve(pos +1 , tight && (d == limit), sum + d,s,m)) % M;
        }
        return dp[pos][tight][sum] = ans;
    }
    int count(string num1, string num2, int min_sum, int max_sum) {
        int n = num1.size();
        int m = num2.size();
        mini = min_sum;
        maxi = max_sum;
        memset(dp,-1,sizeof(dp));
        string L = subtract(num1);
        long long right = solve(0,1,0,num2,num2.size());
        memset(dp,-1,sizeof(dp));
        long long left = solve(0,1,0,L,L.size());
        return (((right - left) % M) + M) % M;
    }
};