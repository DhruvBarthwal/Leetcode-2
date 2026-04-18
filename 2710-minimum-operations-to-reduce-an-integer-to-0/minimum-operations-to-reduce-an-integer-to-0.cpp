class Solution {
public:
    int minOperations(int n) {
        //base case
        if(n == pow(2, (int)log2(n))) return 1;

        int low = pow(2,(int)log2(n));
        int high = pow(2,(int)log2(n) + 1);

        int d1 = n - low;
        int d2 = high - n;
        return 1 + min(minOperations(d1), minOperations(d2));
    }
};