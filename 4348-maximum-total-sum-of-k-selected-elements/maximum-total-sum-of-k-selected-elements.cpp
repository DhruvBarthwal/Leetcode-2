class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        long long ans = 0;
        for(int i = n-1;i>=0;i--){
            if(k == 0) break;
            if(mul > 0){
                ans += (1LL*mul*nums[i]); 
                mul--;
            }
            else{
                ans += nums[i];
            }
            k--;
        }
        return ans;
    }
};