class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        unordered_map<int,int> seen;
        for(int i = 0;i<n;i++){
            if(seen.find(nums[i]) != seen.end()){
                ans.push_back(nums[i]);
            }
            else{
                 seen[nums[i]] = i;
            }
        }
        return ans;
    }
};