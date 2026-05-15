class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int s = 0 , e = n-1;
        if(nums[s] <= nums[e]) return nums[s];
        while(s<e){
            int mid = s + (e-s)/2;
            if(nums[mid] >= nums[0]){
                s = mid + 1;
            }
            else e = mid;
        }
        return nums[e];
    }
};