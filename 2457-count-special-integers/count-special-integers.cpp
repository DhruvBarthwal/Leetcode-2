class Solution {
public:
    int countSpecialNumbers(int n) {
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
        return n - ans;
    }
};