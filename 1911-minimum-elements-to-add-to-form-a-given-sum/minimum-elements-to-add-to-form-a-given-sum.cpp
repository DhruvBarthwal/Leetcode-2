class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long long sum = accumulate(nums.begin(),nums.end(),0LL);

        if(sum == goal) return 0;
        
        long long rem = sum > goal ? sum - goal : goal - sum;

        if(rem <= limit) return 1;

        int temp = rem / limit;
        if(rem % limit != 0) temp++;

        return temp;
    }
};