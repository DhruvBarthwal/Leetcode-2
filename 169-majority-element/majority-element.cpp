class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> count;
        int ans = 0;
        for(int num : nums){
            count[num]++;
            if(count[num] > n/2){
                ans = num;
            }
        }
        return ans;
    }
};