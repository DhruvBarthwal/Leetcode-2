class Solution {
public:
const int M = 1e9+7;
vector<vector<vector<vector<int>>>> dp;
    int solve(int flag,int val, int zero, int one ,int limit){
        //base case
        if(zero == 0 && one == 0) return 1;
        if(dp[zero][one][flag][val] != -1) return dp[zero][one][flag][val];

        long long ans = 0;
        if(zero > 0){
            if(flag == 0){
                if(val < limit) ans += solve(0,val+1,zero-1,one,limit);
            }
            else ans += solve(0,1,zero-1,one,limit);
        }
        if(one > 0){
            if(flag == 1){
                if(val < limit) ans += solve(1,val+1,zero,one-1,limit);
            }
            else ans += solve(1,1,zero,one-1,limit);
        }
        return dp[zero][one][flag][val] = ans % M; 
    }
    int numberOfStableArrays(int zero, int one, int limit) {
        dp.assign(zero+1,vector<vector<vector<int>>>(one + 1,vector<vector<int>>(2,vector<int>(limit + 1,-1))));
        long long ans = 0;
        if(zero > 0) ans += solve(0,1,zero-1,one,limit);
        if(one > 0) ans += solve(1,1,zero,one-1,limit);
        return ans % M;
    }
};