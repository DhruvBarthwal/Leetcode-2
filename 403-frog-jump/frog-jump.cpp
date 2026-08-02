class Solution {
public:
    //global variable
    vector<vector<int>> dp;
    int n;

    bool solve(int i,int k, vector<int>&stones){
        if(i == n-1) return true;

        if(dp[i][k] != -1) return dp[i][k];

        for(int j = i+1;j<n;j++){
            int jump = stones[j] - stones[i];

            if(jump < k-1) continue;
            if(jump > k+1) break;
            if(solve(j,jump,stones)) return dp[i][k] = true;
        }

        return dp[i][k] = false;
    }
    
    bool canCross(vector<int>& stones) {
        //initialization
        n = stones.size();

        if(stones[1] != 1) return false;
        
        dp.assign(n+1,vector<int>(n+1,-1));

        return solve(1,1,stones);
    }
};