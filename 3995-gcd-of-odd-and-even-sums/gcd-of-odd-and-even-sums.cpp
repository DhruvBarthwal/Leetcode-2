class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumOdd = 1, sumEven = 2;
        int i = 1, j = 2;
        int cnt = 1;
        while(cnt != n){
            i += 2;
            sumOdd += i;
            j+= 2;
            sumEven += j;
            cnt++;
        }
        cout<< sumOdd << " "<<sumEven <<endl;
        return gcd(sumOdd, sumEven);    
    }
};