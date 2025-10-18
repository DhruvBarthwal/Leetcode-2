class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        //initialization
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        int prev = INT_MIN;
        for(int i = 0;i<n;i++){
            int val = max(nums[i]-k,prev+1);
            if(val<=nums[i]+k){
                prev = val;
                ans++;
            }
        }
        return ans;
    }
};