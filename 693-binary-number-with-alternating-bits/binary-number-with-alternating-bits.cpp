class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prev = -1;
        while(n > 0){
            if(prev == (n & 1)) return false;
            prev = n & 1;
            cout << prev<<" ";
            n >>= 1;
        }
        return true;
    }
};