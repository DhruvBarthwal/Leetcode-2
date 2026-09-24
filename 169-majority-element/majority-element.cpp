class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidiate = 0;
        int n = nums.size();
        int count =0;

        for(int i = 0;i<n;i++){
            if(count == 0) candidiate = nums[i];
            if(nums[i] == candidiate) count++;
            else count--;
        }
        return candidiate;
    }
};