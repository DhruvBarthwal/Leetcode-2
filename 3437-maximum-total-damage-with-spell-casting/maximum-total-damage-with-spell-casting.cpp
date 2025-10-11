class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        //intialization
        unordered_map<int,long long> count;
        vector<int> key;
        //counting freq
        for(int num : power){
            count[num]++;
        }
        for(auto & [k,_] : count){
            key.push_back(k);
        }
        sort(key.begin(),key.end());
        int n = key.size();
        vector<long long> dp(n);
        dp[0] = count[key[0]] * key[0];
        for(int i = 1;i<n;i++){
            long long take = count[key[i]]*key[i];
            int prev = upper_bound(key.begin(),key.begin()+i,key[i]-3)-key.begin()-1;
            if(prev >=0){
                take += dp[prev];
            }
            dp[i] = max(dp[i-1],take);
        }
        return dp[n-1];
    }
};