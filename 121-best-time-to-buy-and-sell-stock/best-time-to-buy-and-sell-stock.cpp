class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxi =0 , mini = prices[0];
        for(int i =0;i<n;i++){
            int diff = prices[i] - mini;
            mini = min(mini,prices[i]);
            maxi = max(maxi, diff);
        }
        return maxi;
    }
};