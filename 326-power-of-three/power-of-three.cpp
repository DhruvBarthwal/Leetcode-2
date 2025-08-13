class Solution {
public:
    bool isPowerOfThree(int n) {
        //traversal
        for(int i =0;i<n;i++){
            long long val = pow(3,i);
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