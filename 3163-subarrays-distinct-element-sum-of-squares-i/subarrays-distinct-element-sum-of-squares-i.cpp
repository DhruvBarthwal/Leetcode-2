class Solution {
public:
    int sumCounts(vector<int>& nums) {
        __uint128_t mask = 0;
        int n = nums.size();
        int ans = 0;
        for(int i =0;i<n;i++){
            mask = 0;
            int cnt = 0;
            for(int j = i;j<n;j++){
                int x = nums[j];
                cnt += ((mask >> x) & 1) ==  0;
                mask |= ((__uint128_t)1 << x);
                ans += cnt*cnt;
            }
        }
        return ans;
    }
};