class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        if(digits[n-1] < 9){
            digits[n-1]++;
            return digits;
        }
        else{
            int i = n-1;
            int carry = 1;
            while(i >=0 && carry != 0){
                if(digits[i] == 9){
                    digits[i] = 0;
                    carry = 1;
                }
                else{
                    digits[i] ++;
                    carry = 0;
                }
                i--;
            }
            if(carry == 1){
                vector<int> ans;
                ans.push_back(1);
                for(int digit : digits){
                    ans.push_back(digit);
                }
                return ans;
            }
        }
        return digits;
    }
};