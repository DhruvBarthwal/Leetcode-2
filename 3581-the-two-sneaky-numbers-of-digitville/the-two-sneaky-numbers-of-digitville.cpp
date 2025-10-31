class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        unordered_set<int> seen;
        for(int i = 0;i<n;i++){
            if(seen.count(nums[i])){
                ans.push_back(nums[i]);
            }
            else{
                seen.insert(nums[i]);
            }
        }
        return ans;
    }
};