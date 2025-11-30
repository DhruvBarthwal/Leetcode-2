class Solution {
public:
    int reverseBits(int n) {
        int num  = 0;
        for(int i = 0;i<32;i++){
            num = (num << 1) | (n & 1);
            n >>= 1;
        }
        return num;
    }
};