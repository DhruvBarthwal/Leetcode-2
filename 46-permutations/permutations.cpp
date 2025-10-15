class Solution {
public:
void solve(int i , vector<vector<int>>& result, vector<int>&nums){
    if(i == nums.size()){
        result.push_back(nums);
        return;
    }
    for(int j = i;j<nums.size();j++){
        swap(nums[i],nums[j]);
        solve(i+1,result,nums);
        swap(nums[i],nums[j]);
    }
}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        solve(0,result,nums);
        return result;
    }
};