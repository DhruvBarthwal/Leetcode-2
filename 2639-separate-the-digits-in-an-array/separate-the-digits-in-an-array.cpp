class Solution {
public:
    vector<int> ans;
    void solve(int num){
        string s = to_string(num);
        for(int i = 0;i<s.length();i++){
            ans.push_back(s[i] - '0');
        }
    }
    vector<int> separateDigits(vector<int>& nums) {
        for(int i = 0;i<nums.size();i++){
            solve(nums[i]);
        }
        return ans;
    }
};