class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp (n+1,-1);
        //base case
        dp[0] = 0;
        for(int i = 1;i<=n;i++){
            int pass1 = costs[0] + dp[i-1];
            
            int j = i;
            while(j>0 && days[i-1] - days[j-1] < 7){
                j--;
            }
            int pass2 = dp[j] + costs[1];
            
            int k = i;
            while(k>0 && days[i-1] - days[k-1] < 30){
                k--;
            }
            int pass3 = dp[k] + costs[2];
            dp[i] = min({pass1, pass2, pass3});
        }
        return dp[n];
    }
};