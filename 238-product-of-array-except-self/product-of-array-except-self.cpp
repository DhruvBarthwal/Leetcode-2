class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n), prefix(n),suffix(n);
        //for prefix
        prefix[0] = 1;
        for(int i = 1;i<n;i++){
            prefix[i] = nums[i-1]*prefix[i-1];
        }
        //for suffix
        suffix[n-1] = 1;
        for(int i = n-2; i>=0;i--){
            suffix[i] = nums[i+1]*suffix[i+1];
        }
        //traversing the array
        for(int i = 0;i<n;i++){
                int a = prefix[i];
                int b = suffix[i];
                result[i] = a*b;
        }
        return result;
    }
};