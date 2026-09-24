class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        long long sum = accumulate(nums.begin(),nums.end(),0LL);
        int rem = sum - x;
        int n = nums.size();

        if(sum < x) return -1;

        int i = 0;
        sum = 0;
        int best = -1;

        for(int j = 0;j<n;j++){
            sum += nums[j];
            while(sum > rem){
                sum -= nums[i];
                i++;
            }
            if(sum == rem) best = max(best,j-i+1);
        }
        return best == -1 ? -1 : n-best;

    }
};