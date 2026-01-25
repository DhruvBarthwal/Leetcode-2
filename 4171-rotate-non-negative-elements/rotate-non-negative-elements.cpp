class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int> positives;
        int n = nums.size();
        vector<int> ans(n,0);
        for(int i = 0;i<n;i++){
            if(nums[i] >= 0){
                positives.push_back(nums[i]);
            }
            else{
                ans[i] = nums[i];
            }
        }
        int m = positives.size();
        if(m == 0) return nums;
        k = k%m;
        vector<int> temp(m,0);
        for(int i =0;i<m;i++){
            int idx = ((i-k + m)%m);
            temp[idx] = positives[i];
        }
        int j = 0;
        for(int i = 0;i<n;i++){
            if(ans[i] < 0) continue;
            ans[i] = temp[j++];
        }
        return ans;
    }
};