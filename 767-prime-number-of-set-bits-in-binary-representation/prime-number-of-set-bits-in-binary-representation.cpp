class Solution {
public:
bool check(int n){
    return n == 2 || n == 3 || n == 5 || n == 7 || n == 11 || n == 13 || n == 17 || n == 19 || n == 23 || n == 29;
}
    int countPrimeSetBits(int left, int right) {
        int count = 0;
        while(left <=right){
            int num = __builtin_popcount(left);
            if(check(num)) count++;
            left++;
        }
        return count;
    }
};