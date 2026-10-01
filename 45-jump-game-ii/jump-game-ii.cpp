class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        int cnt = 0;
        int jumps = 0;
        int currEnd = 0;
        for(int i =0;i<n-1;i++){
            jumps = max(jumps,i + nums[i]);

            if(i == currEnd){
                cnt++;
                currEnd = jumps;
            }
        }
        return cnt;
    }
};