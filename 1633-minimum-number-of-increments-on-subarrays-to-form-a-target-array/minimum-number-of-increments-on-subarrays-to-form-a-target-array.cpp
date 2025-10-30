class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n = target.size();
        int prev = 0, ans = 0;
        for(int i = 0;i<n;i++){
            int val = target[i] - prev;
            if(val > 0) ans += val;
            prev = target[i];
        }
        return ans;
    }
};