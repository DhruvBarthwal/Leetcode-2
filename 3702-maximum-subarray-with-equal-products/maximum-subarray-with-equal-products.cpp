class Solution {
public:
    int maxLength(vector<int>& nums) {
        int ans = 1;
        int n = nums.size();

        for(int i = 0;i<n;i++){
            int prod = nums[i];
            int g = nums[i];
            int l = nums[i];
            for(int j = i+1;j<n;j++){
                prod *= nums[j];
                g = gcd(g, nums[j]);
                l = l/gcd(l,nums[j]) * nums[j];
                if(prod == g*l) ans = max(ans,j-i+1);
                if(prod > g*l) break;
            }
        }
        return ans;
    }
};