class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        //base case (imp)
        if(num*9 < sum) return "";

        string result = "";
        for(int i = 0;i<num;i++){
            int digit = min(9,sum);
            result += (char)(digit + '0');
            sum -= digit;
        }
        return result;
    }
};