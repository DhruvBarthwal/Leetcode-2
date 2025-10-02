class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n-1;
        long long lsum = 0, rsum = 0;
        //adding s-increasing
        while(l<n-1 && nums[l] < nums[l+1]){
            lsum += nums[l++];
        }
        //adding s-decreasing
        while(r>0 && nums[r] < nums[r-1]){
            rsum += nums[r--];
        }
        long long ans = -1;
        //single peak
        if(l == r){
            long long op1 = abs((lsum + nums[l])-rsum);
            long long op2 = abs(lsum - (rsum + nums[r]));
            ans = min(op1, op2);
        }
        // two peaks
        else if(r-l == 1 && nums[l] == nums[r]){
            ans = abs(lsum-rsum);
        }
        return ans;
    }
};