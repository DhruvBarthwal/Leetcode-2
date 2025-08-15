class Solution {
public:
    bool isPowerOfFour(int n) {
         for(int i = 0;i<n ;i++){
            long long val = pow(4,i);
            if(val == n){
                return true;
                break;
            }
            if(val>n){
                break;
            }
         }
         return false;
    }
};