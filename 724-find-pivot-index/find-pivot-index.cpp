class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n+1), suffix(n+1);
        prefix[0] = 0;
        for(int i =0;i<n;i++){
            prefix[i+1] = nums[i] + prefix[i];
        }
        suffix[n] = 0;
        for(int i = n-1;i>=0;i--){
            suffix[i] = nums[i] + suffix[i+1];
        }
        int ans = -1;
        for(int i = 0;i<n;i++){
            if(prefix[i] == suffix[i+1]){
                ans = i;
                break;
            }
        }
        return ans;
    }
};