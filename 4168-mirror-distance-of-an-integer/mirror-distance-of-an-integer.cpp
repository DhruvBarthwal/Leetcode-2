class Solution {
public:
    int mirrorDistance(int n) {
        int val = 0;
        int num = n;
        while(num >0){
            int d = num%10;
            val = val*10 + d;
            num /= 10;
        }
        return abs(val - n);
    }
};