class Solution {
public:
    int smallestRepunitDivByK(int k) {  
        if(k % 2 == 0 || k% 5 == 0) return -1;
        long long value = 0;
        for(int i = 1;i<=k;i++){
            value = (value * 10 +1)%k;
            if(value == 0){
                return i;
            }
        }
    return -1;
    }
};