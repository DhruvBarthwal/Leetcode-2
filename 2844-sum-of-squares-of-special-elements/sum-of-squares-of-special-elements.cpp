class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i = 1;i*i<=n;i++){
            if(n % i == 0){
                sum += nums[i-1] * nums[i-1];
                if(n/i != i){
                    int val = n/i;
                    sum += nums[val-1] * nums[val-1];
                }
            }
        }
        return sum;
    }
};