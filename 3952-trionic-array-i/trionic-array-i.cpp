class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int i = 0;
        //if starting valus decreasing or equal
        if(nums[i] > nums[i+1] || nums[i] == nums[i+1]) return false;

        while(i<n-1){
            if(nums[i] < nums[i+1]){    //Strictly increasing
                count++;
                while(i < n-1 && nums[i] < nums[i+1]) i++;
            }
            else if (nums[i] > nums[i+1]){ //Strictly decreasing
                count++;
                while(i< n-1 && nums[i] > nums[i+1]) i++;
            }
            else  return false;   //equal values
        }
        return count == 3;
    }
};