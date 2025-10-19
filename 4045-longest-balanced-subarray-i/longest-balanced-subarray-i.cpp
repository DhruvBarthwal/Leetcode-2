class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int odd = 0, even = 0;
        for (int i = 0; i < n; i++) {
            unordered_set<int> e, o;
            for (int j = i; j < n; j++) {
                int val = nums[j];
                if (val & 1) {
                    o.insert(val);
                } else {
                    e.insert(val);
                }
                if (e.size() == o.size()) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};