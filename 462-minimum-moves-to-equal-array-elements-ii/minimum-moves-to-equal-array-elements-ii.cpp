class Solution {

// 4
// 3 4 4 4 2
// 8 6 1
// 1 1 0 5 7
// 1 0 7 8 3/2 = 
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;

        sort(nums.begin(),nums.end());

        int mid = (n-1)/2;

        int cnt = 0;

        for(int &num : nums){
            cnt += abs(num - nums[mid]);
        } 

        return cnt;
    }
};