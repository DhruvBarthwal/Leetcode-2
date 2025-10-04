class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result, prefix(n),suffix(n);
        //for prefix
        prefix[0] = nums[0];
        for(int i = 0;i<n-1;i++){
            prefix[i+1] = nums[i+1]*prefix[i];
        }
        //for suffix
        suffix[n-1] = nums[n-1];
        for(int i = n-1; i>0;i--){
            suffix[i-1] = nums[i-1]*suffix[i];
        }
        //traversing the array
        for(int i = 0;i<n;i++){
            int a,b;
            if(i== 0){
                result.push_back(suffix[1]);
            }
            else if(i == n-1){
                result.push_back(prefix[n-2]);
            }
            else{
                int a = prefix[i-1];
                int b = suffix[i+1];
                result.push_back(a*b);
            }
        }
        return result;
    }
};