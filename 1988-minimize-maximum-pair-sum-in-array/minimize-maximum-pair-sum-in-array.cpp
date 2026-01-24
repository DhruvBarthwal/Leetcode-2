class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        unordered_map<int,int> mp;
        int maxi = 0;
        int n = nums.size();
        int i =0, j = n-1;
        while(i<j){
            maxi = max(nums[i] + nums[j], maxi);
            i++ , j--;
        }
        return maxi;
    }
};