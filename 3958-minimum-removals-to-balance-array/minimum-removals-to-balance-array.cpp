class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = INT_MAX;
        sort(nums.begin(),nums.end());
        for(int i = 0;i<n;i++){
            if(i >= ans) break;
            long long val = (long long)k*nums[i];
            int ub = upper_bound(nums.begin(),nums.end(),val) - nums.begin();
            int rem2 = n - ub;
            int rem1 = i;
            cout<<"ub: "<<ub<<"i: "<<i<<" ";
            ans = min(ans,rem2 + rem1);
        }
        return ans;
    }
};