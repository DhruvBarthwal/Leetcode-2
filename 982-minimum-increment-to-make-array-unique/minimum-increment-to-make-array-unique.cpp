class Solution {
public:
// 1 1 2 2 3 7
// 1 2 2 2 3 7 - 1
// 1 2 3 4 3 7 - 3
// 1 2 3 4 5 7 - 2

// 1 1 1 1 2
// 1 2 3 4 2


    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int maxi = 0;
        int rem = 0;
        int n = nums.size();
        for(int i = 1;i<n;i++){
            if(nums[i-1] >= nums[i]){
                maxi = nums[i-1] + 1;
                rem += maxi - nums[i];
                nums[i] = maxi;
            }
        }
        return rem;
    }
};