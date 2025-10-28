class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        //initialization
        int n = nums.size();
        if(n==1) return 2;
        vector<int> prefix(n);
        prefix[0] = nums[0];
        int count = 0;
        for(int i = 1;i<n;i++){
            prefix[i] = prefix[i-1] + nums[i];
        }
        for(int i = 0;i<n;i++){
            if( (nums[i] == 0)){
                int val1 = prefix[i];
                int val2 = prefix[n-1] - prefix[i];
                if(abs(val1 - val2) == 1){
                    count++;
                }
                else if(val1 - val2 == 0){
                    count+=2;
                }
            }
        }
        return count;
    }
};