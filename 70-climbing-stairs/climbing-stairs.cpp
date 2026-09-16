class Solution {
public:

// 1 orr 2
//no. of d

//1 - 0
//2 - 0 , 1
    // vector<int> dp;
    // int solve(int n){
    //     //base case
    //     if(n == 0 || n == 1)  return 1;
    //     if(dp[n] != -1) return dp[n];

    //     return dp[n] = solve(n-1) + solve(n-2);
    // }

    int climbStairs(int n) {
        int prev1 = 1, prev2 = 1;
        for(int i = 2;i<=n;i++){
            int curr = prev1 + prev2;
            prev1 = prev2;
            prev2 = curr;

        }

        return prev2;
    }
};