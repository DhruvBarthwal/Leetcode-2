class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int a = 0;
        int b = 0;
        int n = nums.size();
        int maxi = *max_element(nums.begin(),nums.end());
        int mini = *min_element(nums.begin(),nums.end());

        for(int i =0; i<n; i++){
            if(nums[i] == mini) a = i+1;
            if(nums[i] == maxi) b = i+1;
        }

        int ans = INT_MAX;
        ans = min(ans, max(a,b));
        ans = min(ans, max(n-a+1,n-b+1));
        ans = min(ans, a + n-b+1);
        ans = min(ans, b + n-a+1);

        return ans;
    }
};