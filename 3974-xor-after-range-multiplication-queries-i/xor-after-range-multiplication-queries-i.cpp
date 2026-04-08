class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        const int M  = 1e9 + 7;
for(int i = 0; i < n; i++){
    long long val = nums[i];
    for(auto &q : queries){
        int l = q[0], r = q[1], step = q[2], mul = q[3];
        if(i >= l && i <= r && (i - l) % step == 0){
            val = (val * mul) % M;
        }
    }
    nums[i] = val;
}
        int ans = nums[0];
        for(int j = 1;j<n;j++){
            ans ^= nums[j];
        }
        return ans;
    }
};