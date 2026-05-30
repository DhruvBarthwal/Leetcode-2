class Solution {
public:
    int minElement(vector<int>& nums) {
        int mini = INT_MAX;
        for(int &num : nums){
            int temp = num;
            int sum = 0;
            while(temp){
                int digit = temp % 10;
                sum += digit;
                temp /= 10;
            }
            mini = min(sum,mini);
        }
        return mini;
    }
};