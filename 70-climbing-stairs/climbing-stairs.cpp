class Solution {
public:
    int climbStairs(int n) {
        int prev = 1 , curr = 1;
        for(int i =2;i<=n;i++){
            int val = prev + curr;
            prev = curr;
            curr = val;
        }
        return curr;
    }
};