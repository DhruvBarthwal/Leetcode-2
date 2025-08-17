class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        //base case
        if(k==0 || n>= k + maxPts){
            return 1.0;
        }
        //initialization
        vector<double> dp(n+1,0.0);
        dp[0] = 1.0;
        double window = 1.0 , result = 0.0;
        //traversing from 1 to n
        for(int i = 1;i<=n;i++){
            dp[i] = window / maxPts;
            if(i<k){
                window += dp[i];
            }
            else{
                result+=dp[i];
            }
            if(i-maxPts>= 0){
                window -= dp[i-maxPts];
            }
        }
        return result;
    }
};