class Solution {
public:
    int maxProduct(int n) {
        int maxi1 = 0;
        int maxi2 = 0;
        int cnt = 0;
        int temp = n;
        while(temp>0){
            int digit = temp % 10;
            maxi1 = max(maxi1,digit);
            temp /= 10;
        }
        temp = n;
        while(temp>0){
            int digit = temp % 10;
            if(digit == maxi1) cnt++;
            temp /= 10;
        }
        if(cnt > 1) return maxi1*maxi1;
        temp = n;
        while(temp>0){
            int digit = temp % 10;
            if(digit != maxi1) maxi2 = max(maxi2,digit);
            temp /= 10;
        }
        return maxi1 * maxi2;
    }
};