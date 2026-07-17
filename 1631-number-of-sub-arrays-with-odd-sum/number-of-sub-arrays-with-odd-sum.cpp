class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        long long total = (long long)n*(n+1)/2;
        unordered_map<long long,long long> mp;
        mp[0] = 1;

        long long sum = 0, ans =0, M = 1e9+7;

        for(int i= 0;i<n;i++){
            sum+= arr[i];
            long long rem = sum % 2;

            if(mp.count(rem)){
                ans = (ans + mp[rem]) % M;
            }
            mp[rem]++;
        }
        return (total - ans) % M;
    }
};