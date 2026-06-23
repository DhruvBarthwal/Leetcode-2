class Solution {
public:
int dp[11][2][1024][2][2];
int m;
    int solve(int pos, int tight, int mask,int started, int repeat, string &s){
        //base case
        if(pos == m) return repeat;
        if(dp[pos][tight][mask][started][repeat] != -1) return dp[pos][tight][mask][started][repeat];

        int limit = tight ? s[pos] - '0' : 9;
        int ans = 0;
        for(int d = 0;d<=limit;d++){
            if(!started && d == 0) ans += solve(pos+1,tight && (d == limit),mask,0,repeat,s);
            else{
                int newRepeated = repeat;
                if(mask & (1 << d)) newRepeated = 1;
                int newMask = mask | (1<<d);
                ans += solve(pos+1,tight && (d == limit), newMask,1, newRepeated, s);
            }
        }
        return dp[pos][tight][mask][started][repeat] = ans; 
    }
    int numDupDigitsAtMostN(int n) {
        string s = to_string(n);
        m = s.length();
        memset(dp, -1, sizeof(dp));
        return solve(0,1,0,0,0,s);
    }
};