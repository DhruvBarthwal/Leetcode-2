class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int left = 0, right = n-1;
        vector<int> ans;
        while(left < right){
            int val = numbers[left] + numbers[right];
            if(val== target){
                ans = {left+1,right+1};
                break;
            }
            else if(val > target) right--;
            else left++;
        }
        return ans;
    }
};