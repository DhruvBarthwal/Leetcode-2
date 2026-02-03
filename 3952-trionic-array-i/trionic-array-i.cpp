class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int i = 0;
        if(nums[i] > nums[i+1] || nums[i] == nums[i+1]) return false;
        while(i<n-1){
            if(nums[i] < nums[i+1]){
                count++;
                while(i < n-1 && nums[i] < nums[i+1]) i++;
            }
            else if (nums[i] > nums[i+1]){
                count++;
                while(i< n-1 && nums[i] > nums[i+1]) i++;
            }
            else  return false;
        }
        return count == 3;
    }
};