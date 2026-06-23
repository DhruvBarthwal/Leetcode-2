class Solution {
public:
// int dp[11][2][1024][2][2];
// int m;
//     int solve(int pos, int tight, int mask,int started, int repeat, string &s){
//         //base case
//         if(pos == m) return repeat;
//         if(dp[pos][tight][mask][started][repeat] != -1) return dp[pos][tight][mask][started][repeat];

//         int limit = tight ? s[pos] - '0' : 9;
//         int ans = 0;
//         for(int d = 0;d<=limit;d++){
//             if(!started && d == 0) ans += solve(pos+1,tight && (d == limit),mask,0,repeat,s);
//             else{
//                 int newRepeated = repeat;
//                 if(mask & (1 << d)) newRepeated = 1;
//                 int newMask = mask | (1<<d);
//                 ans += solve(pos+1,tight && (d == limit), newMask,1, newRepeated, s);
//             }
//         }
//         return dp[pos][tight][mask][started][repeat] = ans; 
//     }
//     int numDupDigitsAtMostN(int n) {
//         string s = to_string(n);
//         m = s.length();
//         memset(dp, -1, sizeof(dp));
//         return solve(0,1,0,0,0,s);
//     }
    int numDupDigitsAtMostN(int n) {
        string st = to_string(n);
        int m = st.length();
        long long dp[11][2][1024][2][2];
        memset(dp, 0, sizeof(dp));
        dp[0][1][0][0][0] = 1;

        for(int pos = 0;pos < m;pos++){
            for(int t = 0;t<2;t++){
                for(int mask = 0;mask<1024;mask++){
                    for(int s = 0;s<2;s++){
                        for(int r = 0;r<2;r++){
                            int ways = dp[pos][t][mask][s][r];
                            if(ways == 0) continue;

                            int limit = t ? st[pos] - '0' : 9;

                            for(int d = 0;d<=limit;d++){
                                int newT = t && (d == limit);
                                if(!s && d == 0) dp[pos+1][newT][mask][0][r] += ways;

                                else{
                                    int newR = r;
                                if(mask & (1 << d)) newR = 1;
                                int newMask = mask | (1 << d);

                                dp[pos+1][newT][newMask][1][newR] += ways;
                                }
                            }
                        }
                    }
                }
            }
        }
        int ans = 0;
        for(int t = 0;t<2;t++){
            for(int mask = 0;mask<1024;mask++){
                for(int s = 0;s<2;s++){
                    ans += dp[m][t][mask][s][1];
                }
            }
        }
        return ans;
    }
};